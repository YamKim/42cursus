#!/bin/sh

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj /C=KR/ST=Seoul/L=Seoul/O=42/OU=Lee/CN=ftpssvc \
	-keyout /etc/ssl/vsftpd.key -out /etc/ssl/vsftpd.crt

mkdir -p /ftps/yekim

adduser --home=/ftps/yekim -D yekim
echo "yekim:5933" | chpasswd

echo "yekim" >> /etc/vsftpd/vsftpd.userlist
touch /var/log/vsftpd.log

/usr/sbin/telegraf/telegraf &
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
