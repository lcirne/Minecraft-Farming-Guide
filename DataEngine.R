
pacman::p_load(dplyr, ggplot2, tidyr, ggrepel) #load packages

args <- commandArgs(trailingOnly = T) #collect arguments from command line

#create a filename variable
filename <- args[1]
cat("Filename received:", filename, "\n")
#read the file into a variable
file <- read.csv(filename)
#code chunk creates a data frame
#makes it easier to manipulate data
file_data <- 
  file |> 
  data.frame()
#file_data #print data frame (debugging)

#extract the yield for the farm and assign to a variable
yield <-
  file_data$yield[nrow(file_data)]
#yield #print yield

#vector for linear farm
consistent_yield_over_time <- numeric(10) #preallocate vector
consistent_yield <- 0 #set updated yield

#vector for exponential farm
exponential_yield_over_time <- numeric(10) #preallocate vector
exponential_yield <- yield
exponential_yield_over_time[1] = yield

#populates a vector called num days from the integers 1-10, incrementing by 1
num_days <- seq(1, 10, 1)

#find the yields over a 10 day span
for (i in num_days) {
  #update data for linear graph
  consistent_yield <- consistent_yield + yield
  consistent_yield_over_time[i] <- consistent_yield
  
  #update data for exponential graph
  if (i > 1) {
    exponential_yield <- exponential_yield * 2
    exponential_yield_over_time[i] <- exponential_yield
  }
}
#consistent_yield_over_time #print consistent_yield_over_time (debugging)
#exponential_yield_over_time #print exponential_yield_over_time (debugging)

#create dataframe of yield values to modify for graphing
graph_yield <- 
  data.frame(num_days, consistent_yield_over_time, exponential_yield_over_time) #creates columns out of the vectors
#modify dataframe
graph_yield_long <- 
  graph_yield |> 
  #combines the yield columns into one and creates a new column
  #where each row denotes the type of yield being represented
  pivot_longer(
    cols = c(consistent_yield_over_time, exponential_yield_over_time),
    names_to = "yield_type",
    values_to = "yield_over_time"
  ) |> 
  mutate(
    yield_type = ifelse(yield_type == "consistent_yield_over_time", "consistent yield", "re-plant yield")
  )

#create plot
yield_plot <- 
#blank graph
  ggplot(
    data = graph_yield_long,
    mapping = aes(
      x = num_days,
      y = yield_over_time,
      color = factor(yield_type)
    )
  ) + geom_line() + #adds two lines to the blank graph to represent each yield type
  theme_bw() + #change general graph aesthetics
  labs( #adds labels to the graph
    title = "Farm Yield Over 10 Minecraft Days",
    x = "Days (In Minecraft)",
    y = "Crop Yield"
  ) + scale_y_continuous( #formats graph margins
    expand = c(0, 0, 0.05, 0)
  ) + theme( #remove legend and center graph title
    legend.position = "none",
    plot.title = element_text(hjust = 0.5)
  ) + 
  #adds labels to the end of each line
  geom_text_repel(
    data = graph_yield_long |>
      #filter for the last day of each month
      #this is the point on the graph the label will be ankered to
      slice_max (
        by = yield_type,
        yield_over_time,
        with_ties = F
      ) |> distinct(), #ensure we only get distinct rows to avoid duplicates
    aes(
      x = num_days - 1, #shift the labels slightly to the left of the lines
      y = yield_over_time,
      label = paste0(yield_type, ": ", yield_over_time) #creates label
    ),
    hjust = 0.5,
    nudge_y = 0,
    direction = "y"
  )

ggsave("Rplots.pdf", plot = yield_plot, width = 8, height = 6) #save plot
system("open Rplots.pdf") #display plot

