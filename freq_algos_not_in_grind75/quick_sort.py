# Python3 implementation of QuickSort


def partition(arr, low, high):
  pivot = arr[low]
  i = low + 1
  j = high

  while True:
    while i <= j and arr[i] <= pivot:
      i += 1
    while i <= j and arr[j] >= pivot:
      j -= 1
    if i <= j:
      arr[i], arr[j] = arr[j], arr[i]
    else:
      break

  arr[low], arr[j] = arr[j], arr[low]
  return j


def quickSort(arr, low, high):
  if low < high:
    pivot_index = partition(arr, low, high)
    quickSort(arr, low, pivot_index - 1)
    quickSort(arr, pivot_index + 1, high)


# Driver code
if __name__ == '__main__':
  array = [1, 1, 1, 1, 1, 7, 6, 8, 5, 5, 8, 3, 4, 5]
  N = len(array)

  # Function call
  quickSort(array, 0, N - 1)
  print('Sorted array:')
  for x in array:
    print(x, end=" ")

# This code is contributed by Adnan Aliakbar
