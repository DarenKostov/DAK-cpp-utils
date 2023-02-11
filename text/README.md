

# Text
\- an attempt at creating a sting-like class for when you don't have access to `std::string`

### Basics

#### Initialize

You can initialize the `Text` with a `char`

    Text('a')

    Text myText='a'

A `char array/pointer`

    "Text("this is a text")

    "Text myText="this is a text"

An `int`/`long`

    Text(32000)

    Text myText=32000

Initialize it empty

    Text()

    Text myText

Or even with another `Text`

    Text(Text("this is another text"))

    Text myText=Text("this is another text")

#### Setting

You can set a `Text` to any of it's initliazable data types


    myText=12321

    myText='F'

#### Concatination

##### Without changing

You can concatinate `Text` with any of it initliazeable data types

    myText+'w'

    myText+"\nthis is a new line"

You can even do it the other way around

    12345+myText

##### With changing

You can also change the `Text` by concatinating something to it

    myText+="this is a text"

#### Comparison

You can compare a `Text` with any of its initlizable data types except `int`/`long`

    bool cmpr= myText=="yet another text"

    bool cmpr= myText==yourText

    bool cmpr= 'q'==myText

#### Get properties

You can get the length of a `Text` (the `'\0'` not included) like this:

    myText.len()

    myText.getLength()

You can get the `Text` in a `char array/pointer` form like this:

(this returns the internal `char*`, no need to (don't) de-allocate it after usage)

(also be aware that after the `Text` variable goes out of cope/is de-allocated this pointer will also be de-allocated)

    myText.val()

    myText.charArr()

    myText.getCharArr()

You can get the `char` at i in the `Text` by doing this:

(by refence)

    myText[i]

    myText.charAt(i)

(by value)

    myText.getCharAt(i)

#### Misc

You can also cast the `Text` to its initializable data times, excluding `int`/`long`

(if it's casted to char it'll give you the 1st `char`)

    (char)Text

    (char*)Text

Each `Text` has also an `id` that is accesible with:

    myText.getId()

It is purely for debugging purposes


### Tips

#### Concatinatio

Want ot concatinate 2 `Texts` into a `char array/pointer`?

    (mytext+yourtext).val()`

    (char*)(mytext+yourtext)`

Want to concatinate 2 `char arrays/pointers` into a `char array/pointer`?

    (Text(myCharArr)+yourCharArr).val()`

Want to set a `char array/pointer` to a `Text`? (make sure there is enough memory in the `char array/pointer`)

    strcpy(myCharArr, myText.val())



