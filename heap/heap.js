const swap = (arr, j, k) => {
  let temp = arr[j];
  arr[j] = arr[k];
  arr[k] = temp;
}

const heapify = (arr, i, size) => {
  if (size === undefined) size = arr.length;
  let largest = i;
  let left = 2 * i + 1; // left child index
  let right = 2 * i + 2; // right child index
  if (size > left && arr[left] > arr[largest]) {
    largest = left;
  }
  if (size > right && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(arr, i, largest)
    heapify(arr, largest, size)
  }
}

const insertItem = (arr, num) => {
  let size = arr.length;
  arr.push(num);
  for (let i = Math.floor(size / 2) - 1; i >= 0; i--) {
    heapify(arr, i);
  }
}

const heapSort = arr => {
  let size = arr.length;
  for (let i = Math.floor(arr.length / 2) - 1; i >= 0; i--) {
    heapify(arr, i);
  }

  for (let i = arr.length - 1; i > 0; i--) {
    swap(arr, 0, i);
    size = size - 1;
    heapify(arr, 0, size);
  }
}

let arr = [9, 4, 7, 1, 11, 15, 13, 14];
heapSort(arr);
insertItem(arr, 3);
heapSort(arr);
console.log(arr)