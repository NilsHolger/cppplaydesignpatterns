# cppplaydesignpatterns
simple modern c++ design patterns

ingenuity: quality of being clever, original and inventive. apply new ideas to solve problems and meet challenges.
innovation: don't imitate, innovate, challenge conventional thinking, why? why not? think differently ...
1. clever
2. original
3. inventive
4. new ideas
5. solve problems
6. meet challenges
7. focus on the goal

push it baby push it ... for all you do this is for you ... rock the house ... 

for these use cases
1. adapter -> wrap an existing library, provide specific functionality to meet the needs of the consumers of the api [adapter.cpp]
2. adapternew -> legacy component is not compatible with system that wants to use it. an abstract base class is created that specifies
the desired interface. an adapter class is defined that publicly inherits interface of abstract class and privately inherits
the implementation of the legacy component. the adapter class maps or impedance matches the new interface to the old implementation. In
the constructor of the adapter the transformation takes place [adapter1.cpp]
3. builder -> object oriented, separate construction of complex object from its representation so that the same construction
process can create different representations [builder.cpp]
4. composite -> identify scalar/primitive classes and vector container classes. all concrete classes implement an interface, they are
all interchangeable. all concrete classes have is a relationship to interface. all container classes couple themselves to interface.
recursive composition, composite has a set of children up the is a hierarchy. container classes use polymorphism as they delegate to
their children [composite.cpp]
5. decorator -> extend functionality, decorate or wrap, statically or dynamically without affecting existing behavior [decorator.cpp, decorator1.cpp]
6. observer -> need to be informed when certain things happen, object's property changes, object does something, some external event happens, listen to events and be notified when they occur. an observer is an object that wishes to be informed when events happen in the system, typically by providing a callback function to call when events occur. the entity generating the events is sometimes called an observable [observer.cpp, observerboost.cpp]
7. state -> the object's behavior is determined by its state, an object transitions from one state to another(something needs to trigger the transition). a formalized contract which manages states and transitions is called a state machine [state.cpp state1.cpp]
8. strategy -> enable the exact behavior of a system to be selected at either run-time (dynamic) or compile-time (static), also known as policy. encapsulate an algorithm in class hierarchy, have clients of that algorithm hold a pointer to base class of hierarchy, delegate all requests for that algorithm to the anonymous contained object [strategy.cpp]
9. template method -> define skeleton of algorithm, concrete implementations in subclasses [template.cpp]
10. chain of responsibility -> a chain of components who all get a chance to process a command or query, optionally having a default processing implementation and an ability to terminate the processing chain. put a next pointer in base class, chain method in base class always delegates to next object, if derived class cannot handle, delegate to base class [cor_pointer.cpp, cor_broker.cpp]
11. command -> an object represents an instruction or sequence of instructions to perform a particular action. contains all information required to execute the action. class encapuslates number of following: receiver object, method to invoke, arguments to pass. instantiate an object for each callback, pass each object to its future sender, when sender ready to callback to receiver, execute is invoked [command1.cpp]
12. interpreter -> given a language define a representation for its grammar along with an interpreter that uses the the representation to interpret sentences in the language, map a domain to a language, language to a grammar, and the grammar to a hierarchical object oriented design. an abstract base class specifies the method interpret, each concrete subclass implements interpret by accepting as an argument the current state state of the language stream and adding its contribution to the problem solving process [interpreter.cpp]
13. iterator -> abstract traversal of wildly different data structures so that algorithms can be defined that are capable of interfacing with each other transparently. access elements of aggregate object sequentially without exposing underlying representation, decouple collection classes and algorithms, promote to full object status traversal of collection, polymorphic traversal [iterator.cpp]
14. mediator -> an object encapsulates how a set of objects interact, loose coupling by keeping objects from referring to each other explicitly, vary their interaction independently, design an intermediary to decouple many peers, promote many to many relationships between interacting peers to full object status [mediator.cpp]
15. memento -> need to restore an object back to its previous state (undo, or rollback), capture and externalize an object's internal state so that the object can be returned to this state later, a magic cookie that encapsulates a checkpoint capability [memento.cpp]
16. facade -> facade takes a riddle wrapped in enigma shrouded in mystery and interjects a wrapper that tames the amorphous and inscrutable mass of software, provide a unified interface to a set of interfaces in a subsystem, define a higher level interface that makes the subsystem easier to use, wrap a complicated subsystem with a simple interface, the facade should not become an all knowing oracle or god object [facade.cpp]
17. flyweight -> space optimization technique, use less memory by storing data externally associated with objects, share objects to allow their use at fine granularity without prohibitive cost, each flyweight object consists of two parts, state dependent extrinsic part, state independent intrinsic part, intrinsic state is stored shared in the flyweight object, extrinsic state is stored computed by client objects and passed to flyweight object when invoked [flyweight.cpp]
18. prototype -> co-opt one instance of a class for use as a breeder of all future instances, specify the kinds of objects to create using a prototypical instance, new operator is considered harmful [prototype.cpp] 

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
Principles behind the Agile Manifesto
We follow these principles:
1. Our highest priority is to satisfy the customer through early and continuous delivery of valuable software.
2. Welcoming changing requirements, even late in development. Agile processes harness change for the customers competitive advantage.
3. Deliver working software frequently, from a couple of weeks to a couple of months, with a preference to the shorter time scale.
4. Business people and developers must work together daily throughout the project.
5. Build projects around motivated individuals. Give them the environment and support they need and trust them to get the job done.
6. The most efficient and effective method of conveying information to and within a development team is face to face conversation.
7. Working software is the primary measure of progress.
8. Agile processes promote sustainable development. The sponsors, developers, and users should be able to maintain a constant pace indefinitely.
9. Continuous attention to technical excellence and good design enhances agility.
10. Simplicity -- the art of maximizing the amount of work done -- is essential.
11. The best architecture , requirements and designs emerge from self organizing teams.
12. At regular interval, the team reflects on how to become more effective, then tunes and adjusts its behavior accordingly. 

--------------------------------------------------------------------
Manifesto for Software Craftsmanship
As aspiring software craftsman we are raising the bar of professional software development by practicing it and helping others learn the craft. Through this work we have come to value:
Not only working software, but also well crafted software
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

push it to the limit. it's all about progress, make our projects progress, make our knowledge base progress, make technology progress, help make the world a better place for all, for the future generations, for they shall have all the comfort of automation and then build on it. imagine the world in 100 years time. what will it be like? if we are able to figure that out now, jackpot ... 100 years ahead ... progress of the human mind .. evolution ... revolution ... many disruptive technologies ahead ... make new ... let's have a lot of fun in the process ... just for fun ... 
let's build the future with love ... the future starts now ... in a perfect world ... what would a perfect world be like ?

what is the sex of the angels? we pondered on this topic in university. i'd say stateless. they must be good and pure, like a new born baby. intellectual masturbation time. some people get paid to do this and professors love talking. talk is cheap, show me the algorithms, facts and nothing but facts. numbers and more numbers and i will believe.
results count. working software. get it done as good and fast as possible that is our reality. the meaning of life is progress. 
with great powers come great responsibilities ... all humans are equal ... i have a dream ... and will push it through to completion ...
i hope everybody has a dream and is living their dreams ... everything starts with a dream ... live your dream ... stream it ...
