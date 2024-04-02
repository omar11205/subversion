class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        # root = root node of the binary search tree
        self.root = None

    # method to insert nodes into the tree
    def insert(self, key):
        self.root = self._insert(self.root, key)  # the definition of _insert can be done later

    """
        Now you need to recursively traverse the tree and insert the values using the principle for binary trees:
        Values smaller than the key are placed in the left subtree
        Values greater than the key are placed in the right subtree
    """
    def _insert(self, node, key):
        """
            Inside the if block, return TreeNode(key) to create a new TreeNode instance with the provided key.
            This will become the new leaf node, effectively inserting the key into the tree.
        """
        if node is None:
            return TreeNode(key)
        if key < node.key:
            # If key < node.key returns True, then the new node should be placed in the left subtree
            node.left = self._insert(node.left, key)
        elif key > node.key:
            node.right = self._insert(node.right, key)
        return node

