
# EDASQL

This is the Data Structure and Algorithms subject final project.

About the project:

It's a console based
database manager, which stores data in 
memory and destroys it when the program is closed.
The data structures used in this project are
binary search trees and doubly Linked List.



## Tech Stack

**C, MakeFile.** 



## Features


#### Create Table
If doesn't exist another table with that name, creates a new table.
```http
    createTable (tableName)
```

#### Drop table

Deletes the table named after 'tableName'.

```http
  dropTable (tableName)
```

#### Add columns

Adds a new column to the indicated table only if it exists.
If the table already contains data, the new column will be filled with 'EMPTY'
values.

```http
  addCol (tableName, colName, colType, colQualifier)
```

| Parameter | Type     | Values accepted     |
| :-------- | :------- | :-------------------------------- |
| `colType` | `string` | INTEGER - STRING |
| `colQualifier` | `string` | NOT_EMPTY - PRIMARY_KEY - ANY |

#### Drop column

Deletes the column indicated, from the table indicated.

```http
  dropCol( tableName, colName )
```

#### Insert tuple

Inserts all the values indicated (separated by ':') on the columns indicated of the table indicated.
if a column of the table indicated it's left unselected, it whill insert the value 'EMPTY'.
Each value corresponds with a column by it's position on the string.

```http
  insertInto (tableName, columns, values)
```

| Parameter | Type     | Values accepted    |
| :-------- | :------- | :-------------------------------- |
| `Columns`| `string` | Col1:col2:col3:...Coln|
| `Values`| `string` | Value1:Value2:Value3:...Valuen|

#### Delete tuples

Deletes all the tuples of the indicated table that meet the condition

```http
  deleteFrom (tableName, deleteCondition)
```

| Parameter | Type     | Values accepted    |
| :-------- | :------- | :-------------------------------- |
| `deleteCondition`| `string` | ColumnName:Operator:Value |
| `Operator`| `string` | > - < - = - ! |


#### Selection

If table1 exist and table2 doesn't exist, creates a table2 with all the tuples that meet the 
condition given in the 'condition' parameter.
PDD: condition has to be in the same format as 'deleteCondition'

```http
   selectWhere (tableName1, condition, tableName2)
```

#### Projection

If table1 exist and table2 doesn't exist, creates a table2 with all the tuples that are contained by the columns indicated
in the 'columns' parameter. All the columns indicated must be part of table1

```http
   select (tableName1, columns, tableName2)
```
| Parameter | Type     | Values accepted    |
| :-------- | :------- | :-------------------------------- |
| `columns`| `string` | col1:col2:col3:...coln |


#### Union

If table1 and table2 exists and table3 doesn't exist, creates a table3 with all the tuples from table1, and table2
only if this two tables have the same metadata.

```http
   union ( tableName1, tableName2, tableName3 )
```

#### Intersection

Likewise the last operation, but for the intersection, that means, the tuples that have the
same values from table1 and table2

```http
   intersect (tableName1, tableName2, tableName3)
```
#### Print table

Prints all the columns and tuples contained in the table indicated.

```http
   printDataTable (tableName)
```
#### Print all tables

Prints the list of tables created in the DB, in ascending order.

```http
    printTables()
```

#### Print metadata

Prints the metadata of the table indicated.
```http
   printMetadata(tableName)
```
## Feedback

If you have any feedback, or comments please reach out to me at federicomaciel.dev@gmail.com or via GitHub.


## Authors

- [My GitHub profile](https://github.com/MacielFede)
- [My LinkedIn profile](https://uy.linkedin.com/in/federico-maciel?trk=people-guest_people_search-card)
