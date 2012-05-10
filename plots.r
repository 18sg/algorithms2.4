#!/usr/bin/env Rscript

source("util.r")
library(lattice)

w <- 7
h <- 6
small_scale <- 0.75

d <- load_datas()

svg(filename="plots/l.svg", width=w, height=h)
wireframe(L ~ num_nodes * out_degree,
	dcast(d, num_nodes + out_degree ~ variable, median,
		subset=.(out_degree > 1 & randomisation==0.5)),
	drape=T,
	screen=list(z = 115, x = -60),
	scales=list(arrows=FALSE),
	col.regions=rainbow(100))

svg(filename="plots/l_rand.svg", width=w, height=h)
wireframe(L ~ randomisation * out_degree,
	dcast(d, randomisation + out_degree ~ variable, median,
		subset=.(num_nodes==10000 & randomisation > 0 & out_degree > 1)),
	drape=T,
	screen=list(z = -130, x = -60),
	scales=list(arrows=FALSE),
	col.regions=rainbow(100),
	scpos=list(x=9, y=5, z=2))

svg(filename="plots/time.svg", width=w * small_scale, height=h * small_scale)
wireframe(time ~ num_nodes * out_degree,
	dcast(d, num_nodes + out_degree ~ variable, median,
		subset=.(randomisation==0.5)),
	drape=T,
	screen=list(z = 30, x = -60),
	scales=list(arrows=FALSE),
	col.regions=rainbow(100))
