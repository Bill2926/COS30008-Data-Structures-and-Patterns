# I recode the bubble and cocktail sort algorithms in Python for fun:)
import math

arr = [1, 7, 5, 19, 150, 23, 99]

def bubbleSort(array):
    # Outer loop: the number of passes
    temp_arr = array.copy()
    arr_size = len(temp_arr)
    for i in range(arr_size - 1):
        for j in range(arr_size - 1 - i):
            if temp_arr[j] > temp_arr[j+1]:
                # temp = array[j]
                # array[j] = array[j+1]
                # array[j+1] = temp

                # Python expert:
                temp_arr[j], temp_arr[j+1] = temp_arr[j+1], temp_arr[j]
    
    return temp_arr

def cockTailSort(array):
    # Descending order
    temp_arr = array.copy()
    arr_size = len(temp_arr)

    for i in range(arr_size // 2):
        for j in range(arr_size - 1 - i):
            if temp_arr[j] < temp_arr[j+1]:
                temp_arr[j], temp_arr[j+1] = temp_arr[j+1], temp_arr[j]
        
        for k in range(arr_size - 2 - i, i - 1, -1):
            if temp_arr[k] < temp_arr[k+1]:
                temp_arr[k], temp_arr[k+1] = temp_arr[k+1], temp_arr[k]
    
    return temp_arr


print(f"Bubble Sort (Asc): {bubbleSort(arr)}")
print(f"Cocktail Sort (Desc): {cockTailSort(arr)}")