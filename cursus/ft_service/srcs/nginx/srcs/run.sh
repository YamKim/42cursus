#!/bin/sh

mkdir -p /run/nginx

adduser -D ${SSH_USER}
echo ${SSH_USER}:${SSH_PASSWD} | chpasswd

/usr/sbin/sshd

/usr/sbin/nginx -g "daemon off;"
