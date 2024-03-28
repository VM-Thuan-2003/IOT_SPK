# x = 3
# print(type(x))
# print(x)
# print(x+1)
# print(x-1)
# print(x*2)
# print(x**2)
# x += 1
# print(x)
# x *= 2
# print(x)
# y=2.5
# print(type(y))
# print(y,y+1,y*2,y**2)

# animals = ['cat', 'dog', 'monkey']
# for animal in animals:
#     print(animal)

# animals = ['cat', 'dog', 'monkey']
# for idx, animal in enumerate(animals):
#     print('#%d: %s' % (idx + 1, animal))


import matplotlib.pyplot as plt
import numpy as np

# a = np.array([1,2,3])
# print(type(a))
# print(a.shape)
# print(a[0],a[1],a[2])
# a[0] = 5
# print(a)
# b = np.array([[1,2,3],[4,5,6]])
# print(b.shape)
# print(b[0,0],b[0,1],b[1,0])

x = np.array([[1, 2], [3, 4]], dtype=np.float64)
y = np.array([[5, 6], [7, 8]], dtype=np.float64)

# print(x+y)
# print(np.add(x,y))
# print(x-y)
# print(np.subtract(x,y))
# print(x*y)
# print(np.multiply(x,y))
# print(x/y)
# print(np.divide(x,y))
# print(np.sqrt(x))

v = np.array([1, 2, 3])
w = np.array([4, 5])
# print(np.reshape(v,(3,1))*w)
# print(x+y)
print("sss", x)
print("ss", x.T)
# print((x.T + w).T)
# print(x + np.reshape(w,(2,1)))
# print(x*2)

# eess = [1,2,3,4,5,6,7]
# casual_avg = [9926,76246,681488,2336640,2835147,4226655,6942042]
# plt.plot(eess,casual_avg)
# plt.show()

# def f(t):
#     return np.exp(-t)*np.cos(2*np.pi*t)
# t1 = np.arange(0.0,5.0,0.1)
# t2 = np.arange(0.0,5.0,0.02)
# plt.subplot(211)
# plt.plot(t1,f(t1),'bo',t2,f(t2))
# plt.title("Example 8 - Multiple Plots")
# plt.subplot(212)
# np.cos(2*np.pi*t2)
# plt.plot(t2,np.cos(2*np.pi*t2))
# plt.show()

plt.bar([1, 3, 5, 7, 9], [5, 2, 7, 8, 2], label="Example one")
plt.bar([2, 3, 6, 8, 10], [8, 6, 2, 5, 6], label="Example two", color='b')
plt.legend()
plt.title('Example 3 - Bar Graph')
plt.ylabel('Bar Number')
plt.xlabel('Bar Height')
plt.show()

# his_1 = np.random.normal(200,1000,5000)
# plt.hist(his_1,bins=50,color='green',edgecolor='black')
# plt.show()
