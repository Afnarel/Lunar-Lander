CC= g++

OBJECTS= Simulateur.o Mobile.o Observateur.o main.o

TARGET= simulateur

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

Simulateur.o : Simulateur.cc Simulateur.h Mobile.cc Mobile.h Observateur.cc Observateur.h
	$(CC) -o Simulateur.o -c Simulateur.cc

Mobile.o : Mobile.cc Mobile.h
	$(CC) -o Mobile.o -c Mobile.cc

Observateur.o : Observateur.cc Observateur.h 
	$(CC) -o Observateur.o -c Observateur.cc

main.o : Simulateur.h Simulateur.cc Mobile.h Observateur.h Mobile.cc Observateur.cc
	$(CC) -o main.o -c main.cc

clean :
	rm -f *~ *.o $(TARGET)
