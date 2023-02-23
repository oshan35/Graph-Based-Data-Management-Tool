# Graph-Based-Data-Management-Tool
Cluster Math is a data management tool such as SQL. Its strongly developed for tabula form data such as csv. You can use cluster math to query the tabula form data. Currently it supports two types of queries. Query language used in cluster math is similer to SQL. It will provide the ability to query and manipulate unstrctured data.
One of the main advantage you can get from cluster math is, it will enable you to run quries and manipulate the unstructured data in console base environment in faster and easier way. Data strcture used in cluster math provides ability to find connections between data points faster other conventional methods.

## User Guid
Cluster math works as a command line application. You can run basic commands and view the exisiting clusters and query them by switching to query mode.

```
create-cluster <Cluster Name> <csv file path>
```
above command will create a data cluster.

To view exisiting clusters 
```

runcommand> list-clusters
+----------------------+
|Cluster Name          |
+----------------------+
|crime-Data-cluster    |
+----------------------+
|social-network-cluster|
+----------------------+
|student-cluster       |
+----------------------+

```

To run queries users can switch into query mode.

```
runcommand> run-query
>select *
>from student-cluster
>where Faculty=ENG;

+--------+------+---+--------+-------+
|Name    |school|age|district|Faculty|
+--------+------+---+--------+-------+
|oshan   |BC    | 23|Gampaha |ENG    |
+--------+------+---+--------+-------+
|ashen   |DV    | 23|Gampaha |ENG    |
+--------+------+---+--------+-------+
|navindu |EX    | 22|Colombo |ENG    |
+--------+------+---+--------+-------+
|Kavindu |SV    | 22|Colombo |ENG    |
+--------+------+---+--------+-------+
|Ravishan|EX    | 21|Mathara |ENG    |
+--------+------+---+--------+-------+
runcommand>

```

Query language is similer to SQL. We have mainly two query types. They are where cluses and relate quries. Where cluses are something similer to SQL where cluses. Relate quries are used to identify indirect connections between data points. It will output the data points which are related directly and indirectly.

```
>select * from social-network-cluster relate Name=Oshan Name=Nehara;
+--------+---------------------+--+-------+----------+----------+
|Gayan   |Bandaranayaka Collage|27|Eshan  |Dinithi   |nan       |
+--------+---------------------+--+-------+----------+----------+
|Oshan   |Bandaranayaka Collage|23|Ananda |Ravishka  |Ranathunga|
+--------+---------------------+--+-------+----------+----------+
|Ravishan|St Peters Collage    |22|Nehra  |Navashan  |Nilantha  |
+--------+---------------------+--+-------+----------+----------+
|Navindu |Isipathana Collage   |22|Ananda |Kavinda   |Nilantha  |
+--------+---------------------+--+-------+----------+----------+
|Pyusha  |Sujatha Collage      |21|Navindu|Rathnasiri|Ramesh    |
+--------+---------------------+--+-------+----------+----------+
|Nehara  |Sujatha Collage      |22|Mahesh |Kithsiri  |Nilantha  |
+--------+---------------------+--+-------+----------+----------+

```
Above example demonstrate the use case of relate query in social network data table. It can idenify the indirect connection between two people in a social network.


