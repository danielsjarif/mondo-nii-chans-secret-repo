Homework４
山口 Mondo :jp:, Daniel Sjarif :neckbeard:, Alex Verdin :tada:
##Problem 1
```python
initial = [0, 7, 4]
temp = []
results = []
commands = ["10", "7", "4"]
steps = []
command = "T"
results.append(initial)
for i in initial:
	if initial[i] == 0:
		i+=1
	else:
		for j in initial and j != i:
			if j == 0 and initial[j] != 10:
				initial[j] += (initial[i] - (initial[j] + initial[i]) - 10)
				initial[i] = (initial[j] + initial[i]) - 10
				command.append("10")
				command.append(commands[i])
				steps.append(command)
				command = "T"
				break
			else if j == 1 and initial[j] != 7:
				initial[j] += (initial[i] - (initial[j] + initial[i]) - 7)
				initial[i] = (initial[j] + initial[i]) - 7
				command.append("7")
				command.append(commands[i])
				steps.append(command)
				command = "T"
				break
			else if j == 1 and initial[j] != 4:
				initial[j] += (initial[i] - (initial[j] + initial[i]) - 4)
				initial[i] = (initial[j] + initial[i]) - 4
				command.append("4")
				command.append(commands[i])
				steps.append(command)
				command = "T"
				break
			for item in results:
				temp = initial
				if initial == item:
					initial = results.length
			if(temp == intial):
				break
print(steps)

```
