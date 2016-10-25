# cppplaydesignpatterns
simple modern c++ design patterns

for these use cases
adapter -> wrap an existing library, provide specific functionality to meet the needs of the consumers of the api
adapternew -> legacy component is not compatible with system that wants to use it. an abstract base class is created that specifies
the desired interface. an adapter class is defined that publicly inherits interface of abstract class and privately inherits
the implementation of the legacy component. the adapter class maps or impedance matches the new interface to the old implementation. In
the constructor of the adapter the transformation takes place
builder -> object oriented, separate construction of complex object from its representation so that the same construction
process can create different representations
composite -> identify scalar/primitive classes and vector container classes. all concrete classes implement an interface, they are
all interchangeable. all concrete classes have is a relationship to interface. all container classes couple themselves to interface.
recursive composition, composite has a set of children up the is a hierarchy. container classes use polymorphism as they delegate to
their children
decorator -> extend functionality, decorate or wrap, statically or dynamically without affecting existing behavior
observer -> need to be informed when certain things happen, object's property changes, object does something, some external event happens, listen to events and be notified when they occur. an observer is an object that wishes to be informed when events happen in the system, typically by providing a callback function to call when events occur. the entity generating the events is sometimes called an observable
state -> the object's behavior is determined by its state, an object transitions from one state to another(something needs to trigger the transition). a formalized contract which manages states and transitions is called a state machine







working software is the goal. as fast and good as possible. write simple, efficient, maintainable code. iterative software development. 100% quality is an iterative process, continuous refactoring of the code base ...
