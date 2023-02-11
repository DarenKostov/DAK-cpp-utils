

# Simple Csv Reader
\- just a tool that reads in csv files and gives you the data in them

#### Initialize

You can initialize it with a file path or none at all

    SCR reader=SCR("/path/to/my/file");

    SCR reader;

#### File setting and stuff

You can open a file to be read with the `open` method

    reader.open("/path/to/my/file");

You can also close that file with the `close` method

    reader.close();


##### File reading & outputting data

You can read the file's column and store it to a std::string vector using the `store` method with the columns name

    reader.store("criteriaA", myVector);


You can also do that just by the index of the column

    reader.store(3, myOtherVector);



###### That's pretty much it

