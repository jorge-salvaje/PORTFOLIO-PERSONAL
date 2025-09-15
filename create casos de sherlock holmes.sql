create table clientes(
id_cliente int primary key,
nombre varchar(50),
apellido varchar(50),
trabajo varchar(50));

create table villanos(
id_villano int primary key,
nombre varchar(50),
apellido varchar(50),
trabajo varchar(50));

create table tipo_de_crimen(
id_tipo_de_Crimen int primary key,
nombre varchar(50));

create table lugares(
id_lugares int primary key,
ciudad varchar(100),
nombre varchar(100));

create table narrador(
id_narrador int primary key,
nombre varchar(50),
apellido varchar(50),
profesion varchar(50));

create table personajes_secundarios(
id_personaje_secundario int primary key,
nombre varchar(50),
apellido varchar(50),
trabajo varchar(50));

create table informacion_del_caso(
id_informacion_del_caso int primary key,
nombre_del_caso varchar(200),
año varchar(4),
id_cliente int,
id_villano int,
id_tipo_de_Crimen int,
id_narrador int,
FOREIGN KEY(id_cliente) REFERENCES clientes(id_cliente),
FOREIGN KEY(id_villano) REFERENCES villanos(id_villano),
FOREIGN KEY(id_tipo_de_Crimen) REFERENCES tipo_de_crimen(id_tipo_de_Crimen),
FOREIGN KEY(id_narrador) REFERENCES narrador(id_narrador));

create table Lugar_Caso(
id_lugar_caso int primary key,
id_informacion_del_caso int,
id_lugares int,
FOREIGN KEY(id_informacion_del_caso) REFERENCES informacion_del_caso(id_informacion_del_caso),
FOREIGN KEY(id_lugares) REFERENCES lugares(id_lugares));

create table caso_secundario(
id_caso_secundario int PRIMARY KEY,
id_informacion_del_caso int,
id_personaje_secundario int,
FOREIGN KEY(id_informacion_del_caso) REFERENCES informacion_del_caso(id_informacion_del_caso),
FOREIGN KEY(id_personaje_secundario) REFERENCES personajes_secundarios(id_personaje_secundario));

alter table narrador
modify column profesion varchar(100);

alter table narrador
add column año_de_nacimiento varchar(4);

insert into clientes(id_cliente,nombre,apellido,trabajo) values('1','Gregson','Lestrade','Inspector'),('2','Mary','Morstan','Institutriz'),('3','James','Mortimer','Medico rural'),('4','Guillermo Gottsreich Sigismond','von Ormstein','Rey de Bohemia'),('5','Jabez','Wilson','Prestamista'),('6','desconocido','desconocido','Miembro de la realeza británica'),('7','John Hector','McFarlane','Abogado'),('8','Thaddeus','Holder','Joyero'),('9','Violet','Hunter','Institutriz'),('10','Mr','Melas','Interprete'),('11','Helen','Stoner','Desconocido'),('12','Susan','Cushing','Desconocido'),('13','Nancy','Devon','Desconocido'),('14','Mr','Rucastle','Terrateniente'),('15','Dr','Wilder','Medico'),('16','Mycroft','Holmes','Empleado del gobierno'),('17','J Neil','Gibson','Propietario de minas'),('18','Fitzroy','MacPherson','Profesor de ciencias'),('19','Sir James','Damery','Funcionario del gobierno británico'),('20','Alice','Turner','Desconocido'),('21','Jhon','Openshaw'
,'Sin ocupacion'),('22','Reginald','Musgrave','Sin ocupacion');                                                                                                          

insert into villanos(id_villano,nombre,apellido,trabajo)
values('1','Jefferson','Hope','Taxista'),('2','Jonathan','Small','Soldado'),('3','Jack','Stapleton','Naturalista'),('4','James','Moriarty','Profesor de matemáticas'),('5','John','Clay','Ladron de bancos'),('6','Irene','Adler','Cantante de Opera y Actriz'),('7','Baron','Gruner','Coleccionista de arte'),('8','BEPPO','Desconocido','Delincuente'),('9','Jonas','Oldacre','Constructor de edificios'),('10','James','Ryder','Trabajador en un hotel'),('11','Jephro','Rucastle','Dueño de casa de campo'),('12','Spiro','Phellips','extorsionador'),('13','Dr. Grimesb','Roylott','Medico'),('14','Jim','Browner','Comerciante de Londres'),('15','Alec','Cunningham','Delincuente'),('16','Stephen','Mortimer','Estudiante de Medicina'),('17','Hugo','Oberstein','Espia Aleman'),('18','Grace','Dunbar','Asesina'),('19','Fitzroy','Mcpherson','Profesor de Latín'),('20','Negretto','Sylvius','Conde'),('21','John','Turner','Desconocido'),('22','Capitan James','Calhoun','Exoficial condecorado'),('23','Rachel','Howells','Doncella'),('24','Neville','St Clair','Periodista');

insert into tipo_de_crimen(id_tipo_de_crimen,nombre)
values('1','Asesinato'),('2','Robo'),('3','Chantaje'),('4','Asesinato en serie'),('5','Fraude'),('6','Falsa Prision'),('7','Secuestro'),('8','Suicidio simulado'),('9','Homicidio por envenenamiento'),('10','Espionaje'),('11','Robo de joyas'),('12','Intento de Asesinato');

insert into narrador(id_narrador,nombre,apellido,profesion,año_de_nacimiento)
values('1','Sherlock','Holmes','Detective Privado','1854'),('2','John H','Watson','Medico','1852'),('3','mycroft','Holmes','Funcionario del Gobierno','1847');

insert into personajes_secundarios(id_personaje_secundario,nombre,apellido,trabajo) values('1','Desconocido','Hudson','Casera'),('2','Tobias','Gregson','Detective'),('3','Athelney','Jones','Detective'),('4','Tadeo','Sholto','Sin ocupacion'),('5','Dr','Mortimer','Doctor'),('6','Eliza','Barrymore','Mayordomo'),('7','Alec','Macdonald','Inspector'),('8','Duque','Ricott','Mayordomo'),('9','Mr','Merryweather','Gerente de banco'),('10','Vincent','Spaulding','Asistente'),('11','Kitty','Winter','Desconocido'),('12','Mr Horace','Harker','Escultor'),('13','Henry','Baker','Dueño de un negocio de gansos'),('14','Alice','Rucastle','Desconocido'),('15','Julia','Stoner','Desconocido'),('16','Bradstreet','Desconocido','Detective'),('17','Mr','Cunningham','Sin ocupacion'),('18','Miss','Mortimer','Desconocido'),('19','Sir James','Walter','Desconocido'),('20','Grace','Dunbar','Institutriz'),('21','Mr','Murdoch','Entrenador de Rugby'),('22','Sam','Merton','Desconocido'),('23','Charles','McCarthy','Terrateniente'),('24','James','McCarthy','Sin ocupacion'),('25','Coronel Elias','Openshaw','Exoficial confederado'),('26','Joseph','Openshaw','Desconocido'),('27','Sir Ralph','Musgrave','Desconocido'),('28','Lady Anne','Musgrave','Sin ocupacion'),('29','Sr Lottie','Hafferty','Desconocido');


insert into informacion_del_caso(id_informacion_del_caso,nombre_del_caso,año,id_cliente,id_villano,id_narrador,id_tipo_de_crimen)
values('1','Un estudio en escarlata','1881','1','1','2','4'),('2','El signo de los cuatro','1888','2','2','2','2'),('3','El sabueso de los Baskerville','1889','3','3','2','1'),('4','El valle del terror','1886','1','4','2','1'),('5','Un escandalo en Bohemia','1888','4','6','2','3'),('6','La liga de los pelirrojos','1890','5','5','2','2'),('7','El cliente ilustre','1902','6','7','2','12'),('8','Los 6 napoleones','1900','1','8','2','1'),('9','El constructor de Norwood','1894','7','9','2','5'),('10','El Carbunclo Azul','1890','8','10','2','11'),('11','La aventura de copper beeches','1890','9','11','2','6'),('12','El interprete griego','1888','10','12','2','7'),('13','La Aventura de la banda de Lunares','1883','11','13','2','1'),('14','La aventura de la caja de carton','1893','12','14','2','1'),('15','El hombre del labio torcido','1889','13','24','2','8'),('16','El escudero de Reigate','1887','14','15','2','2'),('17','El pie del diablo','1897','15','16','2','9'),('18','Los planos de Bruce-Partington','1895','16','17','2','10'),('19','El problema del puente de Thor','1900','17','18','2','1'),('20','La melena del León','1907','18','19','1','1'),('21','La piedra de Mazarino','1903','19','20','2','11'),('22','Las cinco semillas de naranja','1887','21','22','2','1'),('23','El ritual de los musgrave','1879','22','23','1','2'),('24','El misterio de Boscombe Valley','1887','20','21','2','1');

insert into lugares(id_lugares,nombre,ciudad)
values('1','Brixton Road','Londres'),('2','Desierto','Utah'),('3','Casa de Mary Morstan','Londres'),('4','Baker Street','Londres'),('5','Finca de Pondicherry Lodge','Londres'),('6','Baskerville Hall','Devonshire'),('7','Mansion de Birlstone Manor','Sussex'),('8','Valle del terror','Pensilvania'),('9','Casa de Irene Adler','Londres'),('10','Casa de empeños de Jabez Wilson','Londres'),('11','Casa del Barón Gruner','Londres'),('12','Calle Pit','Londres'),('13','Mansion de jonas Oldacre','Londres'),('14','Hotel Cosmopolitan','Londres'),('15','Casa de campo Copper Beeches','Hampshire'),('16','Casa de secuestro','Londres'),('17','Finca de Stoke Moran','Surrey'),('18','Casa de victima','Londres'),('19','Fumadero de Opio','Londres'),('20','Mansion de los Cunningham','Surrey'),('21','Casa del señor Sterndale','Cornualles'),('22','Oficinas del gobierno','Londres'),('23','Estacion de tren','Londres'),('24','Mansion de los Gibson','Hampshire'),('25','Casa del sr McPherson','Sussex'),('26','Cataratas de Reichenbach','Meiringen'),('27','Valle Boscombe','Herefordshire'),('28','Hurlstone Manor','Sussex'),('29','Finca de Horsham','Sussex');

insert into lugar_caso(id_lugar_caso,id_informacion_del_caso,id_lugares)
values('1','1','1'),('2','1','2'),('3','1','4'),('4','2','4'),('5','2','3'),('6','2','5'),('7','3','6'),('8','4','7'),('9','4','8'),('10','4','4'),('11','5','4'),('12','5','9'),('13','6','10'),('14','7','4'),('15','7','11'),('16','8','12'),('17','9','13'),('18','10','4'),('19','10','14'),('20','11','4'),('21','11','15'),('22','12','16'),('23','13','17'),('24','14','18'),('25','15','19'),('26','16','20'),('27','17','21'),('28','18','22'),('29','18','23'),('30','19','24'),('31','20','25'),('32','21','4'),('33','22','29'),('34','22','4'),('35','23','28'),('36','23','4'),('37','24','27');

insert into caso_secundario(id_caso_secundario,id_informacion_del_caso,id_personaje_secundario)
values('1','1','1'),('2','1','2'),('3','2','3'),('4','2','4'),('5','3','5'),('6','3','6'),('7','4','7'),('8','5','8'),('9','6','9'),('10','6','10'),('11','7','11'),('12','8','12'),('13','10','13'),('14','11','14'),('15','13','15'),('16','15','16'),('17','16','17'),('18','17','18'),('19','18','19'),('20','19','20'),('21','20','21'),('22','21','22'),('23','22','23'),('24','22','24'),('25','23','25'),('26','23','26'),('27','24','27'),('28','24','28');

DELETE FROM narrador
where id_narrador='3';

UPDATE lugares
set nombre='221B Baker Street'
where nombre='Baker Street';

update informacion_del_caso set id_tipo_de_Crimen='4' where id_villano='8';

update clientes 
set nombre='G.'
where apellido='Lestrade';

SELECT nombre_del_caso, año, id_cliente from informacion_del_caso;

SELECT nombre from lugares
where ciudad='Sussex';

SELECT nombre_del_caso,año from informacion_del_caso
where id_narrador='1';

SELECT nombre,apellido,profesion,año_de_nacimiento from narrador;

SELECT nombre from lugares
WHERE ciudad='Surrey';

SELECT nombre_del_caso from informacion_del_caso
WHERE id_tipo_de_Crimen='2';

select nombre_del_caso,id_cliente,id_villano from informacion_del_caso
where año BETWEEN 1890 and 1910;

select nombre_del_caso,id_cliente,año from informacion_del_caso
where año not BETWEEN 1890 and 1900;

select nombre,apellido,trabajo from personajes_secundarios
where id_personaje_secundario between 10 and 20;

select nombre_del_caso,id_villano from informacion_del_caso
WHERE id_cliente='1' and id_tipo_de_Crimen='1';

