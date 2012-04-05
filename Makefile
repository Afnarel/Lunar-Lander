CC= g++

OBJECTS= Mobile.o Observateur.o main.o

TARGET= simulateur

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

Mobile.o : Mobile.cc Mobile.h
	$(CC) -o Mobile.o -c Mobile.cc

Observateur.o : Observateur.cc Observateur.h 
	$(CC) -o Observateur.o -c Observateur.cc

main.o : Mobile.h Observateur.h Mobile.cc Observateur.cc
	$(CC) -o main.o -c main.cc

clean :
	rm -f *~ *.o $(TARGET)
