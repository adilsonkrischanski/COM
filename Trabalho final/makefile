all: 
	flex trabalhoFinal.lex
	bison -g --report=states -y -d trabalhoFinal.y
	gcc  lex.yy.c y.tab.c -o trabalhoFinal.out
	rm output.j
	./trabalhoFinal.out

exec: all
	./trabalhoFinal.out

java:
	javac test.java
	javap -c test.class

error: 
	bison --verbose syntax.y

custom_run:
	./trabalhoFinal.out
	java -jar ./jasmin-1.1/jasmin.jar output.j
	java test

jasmine_temp:
	java -jar ./jasmin-1.1/jasmin.jar output.j

run:
	java test

exec_jasm: exec jasmine_temp run
