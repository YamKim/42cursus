CREATE DATABASE myDB;
CREATE USER 'yekim'@'%' IDENTIFIED BY '5933';
GRANT ALL PRIVILEGES ON *.* TO 'yekim'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
