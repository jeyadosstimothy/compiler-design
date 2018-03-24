# compiler-design
Code samples for the following(based on *Dragon Book*) using lex and yacc:
* **ifelse**: Convert *unmatched if* statements into *matched if else* statements by inserting an empty else block
* **loops**: Convert *for loops* and *do..while loops* into *while loops*
* **syntax_tree**: Create a *Syntax Tree* for an arithmetic expression, label the nodes with *Ershov Numbers* and generate *Assembly code* for evaluating the expression based on the node labels
* **three_addr_backpatch**:
  * Create a *Symbol Table* from the input C code
  * Convert *assignment statements(including array references), if statements and while loops* into their equivalent *Three Address Statements* with back patching of addresses
  * Construct *Basic Blocks* from the generated three address statements and form *Flow Graph* for the Basic Blocks
  * Construct *Directed Acyclic Graph(DAG)* for each Basic Block (doesn't work with control statements)
  * Generate new *Three Address Code* from DAG after performing *copy assignment removal* and *constant propagation*

Compiling and executing code: 
* ./compile.sh filename

   For Example: ./compile.sh threeaddr
* ./a.out < inputfile

   For Example: ./a.out < in1.txt
