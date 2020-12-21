#include <QDebug>

#include "PhoneBookReader.h"
#include "PhoneBookWriter.h"
#include "logger.h"
#include "Widget.h"


int main(int argc, char** argv)
{
    PhoneBookReader reader;
    PhoneBookReader::Status status =
            reader.read("../../data/example_phonebook.txt");
    PhoneBook phonebook = reader.getPhoneBook();
    PhoneBookWriter writer;
    writer.write(phonebook, "../../data/written.txt");
    return 0;
}
