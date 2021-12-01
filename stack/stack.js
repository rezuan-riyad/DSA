class Stack {
  constructor(size) {
    this.size = size;
    this.top = -1;
    this.items = [];
  }

  isEmpty() {
    if (this.top < 0) return true;
    else return false;
  }

  isFull() {
    if (this.top == this.size - 1) return true;
    else return false;
  }

  push(elem) {
    if (this.isFull()) {
      console.log("STACK OVERFLOW");
    } else {
      this.top++;
      this.items[this.top] = elem;
    }
  }

  pop() {
    if (this.isEmpty()) {
      console.log("STACK UNDERFLOW");
    } else {
      this.top--;
      return "Element removed: " + this.items[this.top];
    }
  }

  display() {
    console.log("Displaying current stack: ---------- ")
    for (let i = 0; i < this.top + 1; i++) {
      console.log(i+1 + " " +this.items[i])
    }
  }
}

const st = new Stack(8);

const array = [
  "Tiger",
  "Lion",
  "Cat",
  "Cow",
  "Fox",
  "Rabbit",
  "Another Rabbit",
  "Rat",
  "Mouse",
];
array.forEach((elem) => {
  st.push(elem);
});
st.display();
st.pop();
st.pop();
st.pop();
st.display()
st.push("HONUMAN")
st.display()
