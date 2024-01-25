class List:
    """ An ordered collection of elements """

    def __init__(self):
        # The head of the backing linked list:
        self.head = None
        # The number of elements in this list:
        self.size = 0


class Node:
    """ A single node in a linked list """

    def __init__(self, value, next):
        # The value contained in this node:
        self.value = value
        # The next node in the linked list:
        self.next = next


def get(lst, idx):
    pass


def set(lst, idx, value):
    pass


# NOTE: If this is a function rather than a method -- as must be done in a
#       language like C, which has no objects -- it must take an instance of
#       a List as an argument:
def add(lst, idx, value):
    # Create a new node to contain the value.
    # If idx is equal to 0, then:
    #     Set the new node's next to the lst's head.
    #     Set the lst's head to the new node.
    # Else, do:
    #     Set a tmp variable to the lst's head.
    #     For i from 0 to (idx - 1), do:
    #         Set the tmp to the tmp's next.
    #     Set the new node's next to the tmp's next.
    #     Set the tmp's next to the new node.
    # Increment the size.
    pass


# NOTE: The nodes in a linked list are recursively defined:
#         * A single node is the head of a list containing 1 element.
#         * If a node is the head of a list containing n elements, then a new
#           node whose successor is that existing node is the head of a list
#           containing (n + 1) elements.
#       ...the NODES are recursive, but the LIST is not.
def remove(lst, idx):
    lst.head = _remove(lst.head, idx)
    # Decrement the size.
    pass


# NOTE: The input is a node; the output is the node that ought to take its
#       after the remove operation is completed.
def _remove(node, idx):
    # If idx is equal to 0:
    #     Return the node's next -- the node that ought to take its place now
    #      that it has been removed.
    # Else, do:
    #     Recurse on the node's next and (idx - 1) -- this returns the node
    #      that ought to take the next's place.
    #     Set the node's next to the result of recursing.
    #     Return the node -- it has not been removed, so it ought to take its
    #      own place; nothing replaces it.
    pass
