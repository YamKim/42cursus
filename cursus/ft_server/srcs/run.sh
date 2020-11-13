#!/bin/bash

chmod 775 /run.sh
chown -R www-data:www-data /var/www/
chmod -R 775 /var/www/

# ssl key 생성
openssl genrsa -out private.key 2048
openssl rsa -in private.key -pubout -out public.key
openssl req -new -key private.key -subj "/C=KR/ST=Seoul/L=Gangnam/O=42Seoul/OU=Lee/CN=localhost" -out private.csr
openssl req -x509 -days 365 -key private.key -in private.csr -out commoncrt.crt
mv private.key etc/ssl/private/
mv commoncrt.crt etc/ssl/certs/
chmod 600 etc/ssl/private/private.key
chmod 600 etc/ssl/certs/commoncrt.crt

# nginx configuration setting
cp -rp /ft_server/default /etc/nginx/sites-available/

# wordpress installation and setting
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp /ft_server/wp-config.php /var/www/html/wordpress

# wordpress DATABASE setting
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'yekim'@'localhost' IDENTIFIED BY '5933';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'yekim'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password

# phpMyAdmin installation and setting
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
rm phpMyAdmin-5.0.2-all-languages.tar.gz
cp -rp /ft_server/config.inc.php /var/www/html/phpmyadmin/

# remove setting files
rm -f /var/www/html/latest.tar.gz
rm -rf /ft_server

service nginx start
service php7.3-fpm start
service mysql restart
