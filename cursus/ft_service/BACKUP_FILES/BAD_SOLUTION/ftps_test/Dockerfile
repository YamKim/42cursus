FROM alpine:3.12

RUN apk add openssl vsftpd --no-cache

COPY srcs/openssl.conf /etc/ssl/private/
COPY srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY srcs/run.sh /

RUN chmod +x run.sh

EXPOSE 20 21 21100-21104
#ENTRYPOINT ["/run.sh"]
