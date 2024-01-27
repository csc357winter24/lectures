class Dictionary:
    """ A collection of key-value pairs """

    def __init__(self):
        # The length of the backing array:
        self.capacity = 5
        # The backing array:
        self.array = [None] * self.capacity
        # The number of pairs in this dictionary:
        self.size = 0


class Node:
    """ A single node in a linked list """

    def __init__(self, key, value, next):
        # The key contained in this node:
        self.key = key
        # The value contained in this node:
        self.value = value
        # The next node in the linked list:
        self.next = next


def get(dct, key):
    pass


def insert(dct, key, value):
    # If the dct's size is equal to its capacity, then:
    #
    #     NOTE: Once the size exceeds the capacity, a collision is inevitable.
    #
    #     Create a new array -- ideally, the new capacity would be a prime
    #      roughly twice the old capacity, but ((2 * capacity) + 1) is a
    #      reasonable approximation.
    #     Rehash all existing key-value pairs -- their indices were computed
    #      mod the capacity, which has now changed.
    # Hash the given key and mod it by the dct's capacity.
    # If the dct's array at that index is None, then:
    #     Create a new node containing the given key and value.
    #     Set the new node's next to None.
    #     Set the dct's array at that index to the new node.
    #     Increment the size.
    # Else, do:
    #     Set a tmp variable to the dct's array at that index -- this is the
    #      head of a non-empty linked list.
    #     While the tmp's key is not equal to the given key:
    #         If the tmp's next is None, then:
    #             Create a new node containing the given key.
    #             Set the new node's next to None.
    #             Set the tmp's next to the new node.
    #             Increment the size.
    #         Set the tmp to the tmp's next.
    #
    #     NOTE: The only way to reach this line is if tmp refers to a node that
    #           contains the given key.
    #
    #     Set the tmp's value to the given value.
    pass


def remove(dct, key):
    # Hash the given key, search the corresponding list, etc...
    #
    # NOTE: If the removed node was the only node in its linked list, then the
    #       array element must be reset to None, since the list is now empty.
    pass


def keys(dct):
    pass
