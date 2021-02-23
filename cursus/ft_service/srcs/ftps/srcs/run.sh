#!/bin/sh

mkdir -p /ftps/yekim

adduser --home=/ftps/yekim -D yekim
echo "yekim:5933" | chpasswd

echo "yekim" >> /etc/vsftpd/vsftpd.userlist
touch /var/log/vsftpd.log

/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
