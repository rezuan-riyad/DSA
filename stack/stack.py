# Stack implementaion in python

#Creating a stack
def create_stack():
  stack = []
  return stack

#Creating an empty stack
def check_empty(stack):
  return len(stack) == 0

# Adding items into the stack
def push(stack, item):
  stack.append(item)

def pop(stack):
  if(check_empty(stack)):
    return
  return stack.pop()

stack = create_stack()
lst = [1,4,3,5,32,2,3,4,4]
for item in lst:
  push(stack, item)

pop(stack)
print(stack)
