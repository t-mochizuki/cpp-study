# Principal

- 流動的要素をカプセル化する
- クラス継承よりもオブジェクト集約を多用する

# Diagram

## Factory Method Pattern

```mermaid
classDiagram

class Creator {
  factoryMethod()*
}

class ConcreteCreator {
  factoryMethod()
}

Creator <|-- ConcreteCreator
Product <|-- ConcreteProduct
ConcreteCreator ..> ConcreteProduct
```
