# Article

<!--@START_MENU_TOKEN@-->Summary<!--@END_MENU_TOKEN@-->

## Overview

<!--@START_MENU_TOKEN@-->Text<!--@END_MENU_TOKEN@-->

## Topics

### Facade

Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

### FlyWeight

Use sharing to support large numbers of fine-grained objects efficiently.

### Proxy

Provide a surrogate or placeholder for another object to control access to it.
Example: proxy Image while actual takes time to download from remote or only when user clicks to see.

- <!--@START_MENU_TOKEN@-->``Symbol``<!--@END_MENU_TOKEN@-->

## Behavioral

### Chain of Responsibility

Intent: Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.

Please refer Composite pattern. Here, If someone wants to take responsibility then the recursiveness is stopped.

### Command

Intent: Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

Example: Open Command to open a document. Paste Command to paste in a document.

### Interprter

Intent: Given a language, define a represention for its grammar along with an interpreter that uses the representation to interpret sentences in the language.
Mostly used for compilers.

### Iterator

Intent: Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

Example: STL iterator for vector

### Mediator

Example: Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.


