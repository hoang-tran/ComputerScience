import UIKit

class TreeNode {
  var value: Int = 0
  var left: TreeNode? = nil
  var right: TreeNode? = nil

  init(value: Int) {
    self.value = value
  }

  func insert(value: Int) {
    insert(value, node: self)
  }

  func search(value: Int) -> TreeNode? {
    return search(value, node: self)
  }

  func isBST() -> Bool {
    return isBST(self, minValue: Int.min, maxValue: Int.max)
  }

  func delete(value: Int) -> TreeNode? {
    return delete(value, node: self)
  }

  func delete(value: Int, node: TreeNode?) -> TreeNode? {
    guard let node = node else { return nil }
    if value == node.value {
      if let left = node.left, _ = node.right {
        let (maxNodeOnLeftSubtree, parentNode) = left.findMax(node)
        node.value = maxNodeOnLeftSubtree.value
        if parentNode === node {
          node.left = delete(maxNodeOnLeftSubtree.value, node: maxNodeOnLeftSubtree)
        } else {
          parentNode.right = delete(maxNodeOnLeftSubtree.value, node: maxNodeOnLeftSubtree)
        }
      } else {
        if let left = node.left {
          node.left = nil
          return left
        } else if let right = node.right {
          node.right = nil
          return right
        } else {
          return nil
        }
      }
    } else if value < node.value {
      node.left = delete(value, node: node.left)
    } else {
      node.right = delete(value, node: node.right)
    }
    return node
  }

  func isBST(node: TreeNode?, minValue: Int, maxValue: Int) -> Bool {
    guard let node = node else { return true }
    if node.value < minValue || node.value > maxValue { return false }
    return isBST(node.left, minValue: minValue, maxValue: node.value)
      && isBST(node.right, minValue: node.value, maxValue: maxValue)
  }

  func insert(value: Int, node: TreeNode?) -> TreeNode {
    if let node = node {
      if value == node.value {
        node.value = value
      } else if value < node.value {
        node.left = insert(value, node: node.left)
      } else {
        node.right = insert(value, node: node.right)
      }
      return node
    } else {
      return TreeNode(value: value)
    }
  }

  func search(value: Int, node: TreeNode?) -> TreeNode? {
    guard let node = node else { return nil }
    if value == node.value {
      return node
    } else if value < node.value {
      return search(value, node: node.left)
    } else {
      return search(value, node: node.right)
    }
  }
}

extension TreeNode {
  func findMax(parentNode: TreeNode!) -> (TreeNode!, TreeNode!) {
    var node = self
    var parentNode = parentNode
    while node.right != nil {
      parentNode = node
      node = node.right!
    }
    return (node, parentNode)
  }

  func generateTree() {
    insert(2)
    insert(6)
    insert(1)
    insert(9)
    insert(3)
    insert(4)
    insert(7)
    insert(8)
  }

  func printTree() -> String {
    var resultString = ""
    printTree(self, resultString: &resultString)
    return resultString
  }

  func printTree(currentNode: TreeNode?, inout resultString: String) {
    guard let currentNode = currentNode else { return }
    printTree(currentNode.left, resultString: &resultString)
    resultString += "\(currentNode.value) "
    printTree(currentNode.right, resultString: &resultString)
  }

}

var root: TreeNode? = TreeNode(value: 5)
root?.generateTree()
print(root?.printTree())
print(root?.isBST())
root = root?.delete(3)
root = root?.delete(5)
root = root?.delete(7)
root = root?.delete(6)
root = root?.delete(2)
root = root?.delete(1)
root = root?.delete(9)
root = root?.delete(8)
root = root?.delete(4)
print(root)