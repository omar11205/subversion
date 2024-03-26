"""
    The merge sort algorithm mainly performs three actions:

    1. Divide an unsorted sequence of items into sub-parts
    2. Sort the items in the sub-parts
    3. Merge the sorted sub-parts
    The above happens recursively until the sub-parts are merged into the complete sorted sequence
"""


def merge_sort(array):
    # // = integer division operator
    middle_point = len(array) // 2
    # using left syntax extract the left half of array.
    # array[start:stop:step] (indices starts with zeros)
    # the start index specifies the index that the slicing starts from, the default is 0
    # the end index specifies the index where the slicing ends
    # (but excluding the value at this index). The default is the length fo the array
    # the step argument specifies the step of the slicing. The default is 1
    # slicing without a start or end index, basically creates a whole copy of the array_copy = array[:],
    # because the defaults values are array[0:length_of_the_array:1]
    # to slice with a start index: copy_excluding_the_first_5_elements = array[4:], the default values are filled
    # like this ... = array[4:length_of_the_array:1] this produces a slice of the last five elements
    left_part = array[:middle_point]
    right_part = array[middle_point:]
    # recursive merge sort to break the array in to individual parts
    merge_sort(left_part)
