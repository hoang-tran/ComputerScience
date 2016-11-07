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

  func delete(value: Int) {

  }

  func delete(value: Int, node: TreeNode?) -> TreeNode? {
    guard let node = node else { return nil }
    if value == node.value {
      if node.left == nil && node.right == nil {
        return nil
      } else {
        if let left = node.left, right = node.right {
          let maxNodeOnLeftSubtree = findMax(node.left)
          node.value = maxNodeOnLeftSubtree.value
          delete(maxNodeOnLeftSubtree.value, maxNodeOnLeftSubtree)
        } else {
          if let left = node.left {
            node.left = nil
            return left
          } else if let right = node.right {
            node.right = nil
            return right
          }
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
  func findMax(node: TreeNode?, maxValue: Int) -> TreeNode? {
    guard let node = node { return nil }
    if node.value > maxValue {

    }
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

  func printTree() {
    var resultString = ""
    printTree(self, resultString: &resultString)
    print(resultString)
  }

  func printTree(currentNode: TreeNode?, inout resultString: String) {
    guard let currentNode = currentNode else { return }
    printTree(currentNode.left, resultString: &resultString)
    resultString += "\(currentNode.value) "
    printTree(currentNode.right, resultString: &resultString)
  }
  
}

let root = TreeNode(value: 5)
root.generateTree()
root.printTree()
print(root.isBST())
