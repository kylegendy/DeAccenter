# DeAccenter
## Table of Contents

1. [Objective](#objective)
2. [Outline](#outline)
    1. [General](#general)
    2. [Object Details](#object-details)
        1. [DeAccenter Class](#deaccenter-class)
    
## Objective

Create a system of determining whether a given symbol contains a diacritic, ie an accent, for any and all germanic
characters.  Additionally, be able to translate said accented symbol into its unaccented base form.  This will allow for
more standard reading of documents/inputs.

## Outline

### General
The DeAccenter class is an object that, once initialized, can take in strings and determine if they have diacritics and 
replace the symbol with its unaccented base form.
This project is especially annoying since diacritics are implemented differently between operating systems, and also
that diacritics utilize pairs of characters rather than a single character.  For example, if you have a single symbol in
a string with a diacritic, such as 'À', calling size() on this string would return 2.  Thus, in order to account for
taking in two characters while maintaining an ease of interface, DeAccenter methods take and return std::strings, some
of which assert a string having only two characters.

### Object Details

#### DeAccenter Class
##### Description
This class creates a hash map upon initialization that's keys are accented symbols and mapped types are the
corresponding base, unaccented characters.

##### Member Variables:
variable | description
---------|---------
std::unordered_map\<std::string,char32_t> hash; | a container that maps all germanic symbols with accents to the same germanic chars without accents

##### Member Functions:
signature | description
----------|-----------
explicit DeAccenter(); | def constructor
bool isAccented(const std::string& string, uint32_t index) const; | determines if a symbol is a germanic letter with an accent at index, capital or lowercase
bool containsAccent(const std::string& string) const; | determines if a string contains a germanic symbol with an accent, capital or lowercase
std::string removeAccent(const std::string& string, uint32_t index) const; | if the given parameter is a germanic character with an accent, it will return the germanic character without an accent, capital or lowercase
std::string removeAllAccents(const std::string& string) const; | replaces any germanic symbols with accents with their base, unaccented characters