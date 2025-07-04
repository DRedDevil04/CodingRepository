echo "[ Setup proxy ]"
echo "Don't forget to URL-encode host, port and password."
echo -n "Host: "
read PROXY_HOST
echo -n "Port: "
read PROXY_PORT
echo -n "Username: "
read PROXY_USER
echo -n "Password: "
read -s PROXY_PASSWORD

PROXY_STRING="http://$PROXY_USER:$PROXY_PASSWORD@$PROXY_HOST:$PROXY_PORT/"

# Set environment variables

export http_proxy=$PROXY_STRING
export HTTP_PROXY=$PROXY_STRING

export https_proxy=$PROXY_STRING
export HTTPS_PROXY=$PROXY_STRING

export ftp_proxy=$PROXY_STRING
export FTP_PROXY=$PROXY_STRING

export socks_proxy=$PROXY_STRING
export SOCKS_PROXY=$PROXY_STRING

export all_proxy=$PROXY_STRING
export ALL_PROXY=$PROXY_STRING

# Set Gnome settings

gsettings set org.gnome.system.proxy mode 'manual';

gsettings set org.gnome.system.proxy.http host "'$PROXY_HOST'";
gsettings set org.gnome.system.proxy.http port $PROXY_PORT;
gsettings set org.gnome.system.proxy.http authentication-user "'$PROXY_USER'";
gsettings set org.gnome.system.proxy.http authentication-password "'$PROXY_PASSWORD'";

gsettings set org.gnome.system.proxy.https host "'$PROXY_HOST'";
gsettings set org.gnome.system.proxy.https port $PROXY_PORT;

gsettings set org.gnome.system.proxy.ftp host "'$PROXY_HOST'";
gsettings set org.gnome.system.proxy.ftp port $PROXY_PORT;

# Set apt proxy settings

echo
echo "Sudo privileges required to write to /etc/apt/apt.conf.d/proxy"
apt_conf_proxy="
Acquire::http::Proxy \"$PROXY_STRING\";
Acquire::https::Proxy \"$PROXY_STRING\";
Acquire::ftp::Proxy \"$PROXY_STRING\";
"
echo "$apt_conf_proxy" | sudo tee /etc/apt/apt.conf.d/proxy > /dev/null

echo "Proxy enabled."
