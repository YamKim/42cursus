CREATE DATABASE wordpress;
CREATE USER 'PMA_USER'@'%' IDENTIFIED BY 'PMA_PASSWD';
GRANT ALL PRIVILEGES ON *.* TO 'PMA_USER'@'%' WITH GRANT OPTION;
CREATE USER 'WP_USER'@'%' IDENTIFIED BY 'WP_PASSWORD';
GRANT ALL PRIVILIEGES ON wordpress.* TO 'WP_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
