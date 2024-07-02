from pyecharts.charts import Line

line = Line()
line.add_xaxis(["美国", "中国", "日本"])
line.add_yaxis("GDP", ["0", "10000", "0"])
line.render()

