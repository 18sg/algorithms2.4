library(reshape2)
# library(ggplot2)
library(plyr)

load_data <- function(f="data/1") {
	melt(
		read.csv(f),
		id=c("num_nodes", "out_degree", "randomisation"))
}

load_datas <- function(fs=c("data/1", "data/2", "data/3")) {
	melt(
		do.call("rbind", lapply(fs, read.csv)),
		id=c("num_nodes", "out_degree", "randomisation"))
}
