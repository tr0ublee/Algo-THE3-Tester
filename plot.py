import matplotlib.pyplot as plt

def plot_asym():
	results = []

	with open('./asym-teststimes.txt', 'r') as res:
		line = res.readline()
		n = int(line)
		line = res.readline()
		while line:
			results.append(float(line))
			line = res.readline()
	n-=1
	xaxis = list(range(n))
	for i in range(1,n):
		results[i] /= i*i*i
	plt.plot(xaxis, results)
	plt.legend(['Time / N^3, must be constant as N->infinity'])
	plt.savefig('plot.png')
	#plt.show()
	

if __name__ == "__main__":
	plot_asym()