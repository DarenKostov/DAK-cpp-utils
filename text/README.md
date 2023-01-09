

# Text
\- an attempt at creating a sting-like class for when you don't have access to std::string

### Basics

#### Initialize

You can initialize the Text with a char

`Text('a')`

`Text mytext='a'`

A char array/pointer

`"Text("this is a text")`

`"Text mytext="this is a text"`

An int/long

`Text(32000)`

`Text mytext=32000`

Initialize it empty

`Text()`

`Text mytext`

Or even with another Text

`Text(Text("this is another text"))`

`Text mytext=Text("this is another text")`

#### Setting

You can set a text to any of it's initliazable data types


`mytext=12321`

`mytext='F'`

#### Concatination

##### Without changing

You can concatinate Text with any of it initliazeable data types

`mytext+'w'`

`mytext+"\nthis is a new line"`

You can even do it the other way around

`12345+mytext`

##### With changing

You can also change the Text by concatinating something to it

`mytext+="this is a text"`

#### Comparison

You can compare a Text with any of its initlizable data types except int/long

`bool cmpr= mytext=="yet another text"`

`bool cmpr= mytext==yourtext`

`bool cmpr= 'q'==mytext`

#### Get properties

You can get the length of a Text (the '\0' not included) like this:

`mytext.len()`

`mytext.getLength()`

You can get the Text in a char array/pointer form like this:

`mytext.val()`

`mytext.charArr()`

`mytext.getCharArr()`

You can get the char at i in the Text by doing this:

(by refence)

`mytext[i]`

`mytext.charAt(i)`

(by value)

`mytext.getCharAt(i)`

#### Misc

You can also cast the Text to its initializable data times, excluding int/long

(if it's casted to char it'll give you the 1st char)

`(char)Text`

`(char*)Text`

Each Text has also an id that is accesible with:

`mytext.getId()`

It is purely for debugging purposes


### Tips

#### Concatinatio

Whant ot concatinate 2 Texts into a char array?

`(mytext+yourtext).val()` 

`(char*)(mytext+yourtext)` 

Want to concatinate 2 char arrays into a char array?

`(Text(mytext)+yourtext)` 

Want to set a char array onto to a Text? (make sure ther is enough space in the char array)

`strcpy(myCharArr, mytext.val())`



