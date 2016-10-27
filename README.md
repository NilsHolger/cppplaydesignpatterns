# cppplaydesignpatterns
simple modern c++ design patterns

flag->ingenuity: quality of being clever, original and inventive. apply new ideas to solve problems and meet challenges.

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
strategy -> enable the exact behavior of a system to be selected at either run-time (dynamic) or compile-time (static), also known as policy. encapsulate an algorithm in class hierarchy, have clients of that algorithm hold a pointer to base class of hierarchy, delegate all requests for that algorithm to the anonymous contained object
template method -> define skeleton of algorithm, concrete implementations in subclasses
chain of responsibility -> a chain of components who all get a chance to process a command or query, optionally having a default processing implementation and an ability to terminate the processing chain. put a next pointer in base class, chain method in base class always delegates to next object, if derived class cannot handle, delegate to base class
command -> an object represents an instruction or sequence of instructions to perform a particular action. contains all information required to execute the action. class encapuslates number of following: receiver object, method to invoke, arguments to pass. instantiate an object for each callback, pass each object to its future sender, when sender ready to callback to receiver, execute is invoked

--------------------------------------------------------------------
Manifesto for Agile Software Development
We are uncovering better ways of developing software by doing it and helping others do it. Through this work we have come to value:
Individuals and interactions over processes and tools.
Working software over comprehensive documentation.
Customer collaboration over contract negotiation.
Responding to change over following a plan.
While there is value in items on the right we value items on the left more.
1. Individuals and interactions
2. Working software
3. Customer Collaboration
4. Responding to change

--------------------------------------------------------------------

--------------------------------------------------------------------
Manifesto for Software Craftsmanship
As aspiring software craftsman we are raising the bar of professional software development by practicing it and helping others learn the craft. Through this work we have come to value:
Not only working software, but also well crafted software [made with love]
Not only responding to change, but also steadily adding value
Not only individuals and interactions, but also a community of professionals
Not only customer collaboration, but also productive partnerships
That is in pursuit of items on the left, we have found the items on the right to be indispensable.
1. Well crafted software
2. Steadily adding value
3. Community of professionals
4. Productive partnerships

--------------------------------------------------------------------

working software is the goal. as fast and good as possible. write simple, efficient, maintainable code. iterative software development. 100% quality is an iterative process, continuous refactoring of the code base ...
innovation is 1% inspiration and 99% perspiration(syntactic sugar sweet sweat), innovators, risk lovers, take calculated risks, large knowledge base -> connect many algorithms, formalize new ones, the base is a large knowledge base ... trial and error process

if god were among us, we would hold him for completely irrational, because he would never do the same thing twice ...

A special shoutout to my project manager, you're awesome, and colleagues, you guys are all awesome, super bright ueber geeks. you bring out the best in me. team work. high performance teams ... push it to the limit. we can and we will. it's all about progress, make our projects progress, make our knowledge base progress, make technology progress, help make the world a better place for all, for the future generations, for they shall have all the comfort of automation and then build on it. imagine the world in 100 years time. what will it be like? if we are able to figure that out now, jackpot ... 100 years ahead ... progress of the human mind .. evolution ... revolution ... many disruptive technologies ahead ... make new ... let's have a lot of fun in the process ... just for fun ... 
let's build the future with love ... the future starts now ... in a perfect world ... what would a perfect world be like ?
