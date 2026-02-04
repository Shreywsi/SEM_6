def perceptron(inputs, weights):
    if len(inputs) != len(weights):
        raise ValueError("Number of inputs and weights must be the same")
    
  
    weighted_sum = 0
    for i in range(len(inputs)):
        weighted_sum += inputs[i] * weights[i]    
    if weighted_sum >= 0:
        return 1
    else:
        return 0


inputs = [1, 1]
weights = [0.5, 0.5]

output = perceptron(inputs, weights)

print("Inputs:", inputs)
print("Weights:", weights)
weighted_sum = 0
for i in range(len(inputs)):
    weighted_sum += inputs[i] * weights[i]

print("Weighted Sum:", weighted_sum)

print("Perceptron Output:", output)
