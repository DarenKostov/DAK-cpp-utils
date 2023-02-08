

# Simple Csv Reader
\- just a tool that reads in csv files and gives you the data in them

#### Initialize

You can initialize it with a file path or none at all

`SCR reader=SCR("/path/to/my/file");`

`SCR reader;`

#### File setting and stuff

You can open a file to be read with the "open" method

`reader.open("/path/to/my/file");`

You can also close that file with the "close" method

`reader.close();`


##### File reading

You can read the file's columns and output them to a string vector using the read method with the columns name

`reader.read("criteriaA", myVector)`


You can also do that just by the index of the column

`reader.read(3, myOtherVector)`


BTW the vector must be of type std::string

###### That's pretty much it

