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
    # If the idx is equal to 0, then:
    #     Set the new node's next to the lst's head.
    #     Set lst's head to the new node.
    # Else, do:
    #     Set a tmp variable equal to lst's head.
    #     For i from 0 to idx - 1, do:
    #         Set tmp equal to tmp's next.
    #     Set the new node's next to tmp's next.
    #     Set tmp's next to the new node.
    # Increment the lst's size.
    pass


# NOTE: The nodes in a linked list are recursively defined:
#         * A single node is the head of a list of 1 element.
#         * If a node is the head of a list of n elements, then a new node with
#           that node as its successor is the head of a list of n+1 elements.
#       ...the NODES are recursively defined, but the LIST itself is not.
def remove(lst, idx):
    # If the idx is equal to 0, then:
    #     Set the lst's head to the lst's head's next.
    # Else, do:
    #     (find the previous node, etc... -- see above)
    #
    #  or
    #
    # Call _remove on the lst's head.
    # Decrement the size.
    pass


def _remove(node, idx):
    # If idx is equal to 0, then:
    #     Return the node's next -- the next node takes the place of the
    #      current (now removed) node.
    # Else, do:
    #     Set the node's next to the result of recursing on the node's next
    #      with idx - 1 -- that is, the node that takes the place of the
    #      current (NOT removed) node's next.
    #     Return the current (NOT removed) node -- nothing takes its place.
    pass
