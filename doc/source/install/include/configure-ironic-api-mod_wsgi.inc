Configuring ironic-api behind mod_wsgi
--------------------------------------

Bare Metal service comes with an example file for configuring the
``ironic-api`` service to run behind Apache with mod_wsgi.

#. Install the apache service:

   RHEL7/CentOS7::

       sudo yum install httpd

   Fedora::

       sudo dnf install httpd

   Debian/Ubuntu::

       apt-get install apache2

   SUSE::

       zypper install apache2


#. Download the ``etc/apache2/ironic`` file from the Ironic project tree and
   copy it to the apache sites:

   Fedora/RHEL7/CentOS7::

       sudo cp etc/apache2/ironic /etc/httpd/conf.d/ironic.conf

   Debian/Ubuntu::

       sudo cp etc/apache2/ironic /etc/apache2/sites-available/ironic.conf

   SUSE::

       sudo cp etc/apache2/ironic /etc/apache2/vhosts.d/ironic.conf


#. Edit the recently copied ``<apache-configuration-dir>/ironic.conf``:

   #. Modify the ``WSGIDaemonProcess``, ``APACHE_RUN_USER`` and
      ``APACHE_RUN_GROUP`` directives to set the user and group values to
      an appropriate user on your server.

   #. Modify the ``WSGIScriptAlias`` directive to point to the automatically
      generated ``ironic-api-wsgi`` script that is located in `IRONIC_BIN`
      directory.

   #. Modify the ``Directory`` directive to set the path to the Ironic API code.

   #. Modify the ``ErrorLog`` and ``CustomLog`` to redirect the logs
      to the right directory (on Red Hat systems this is usually under
      /var/log/httpd).

#. Enable the apache ``ironic`` in site and reload:

   Fedora/RHEL7/CentOS7::

       sudo systemctl reload httpd

   Debian/Ubuntu::

       sudo a2ensite ironic
       sudo service apache2 reload

   SUSE::

       sudo systemctl reload apache2

.. note::
   The file ``ironic-api-wsgi`` is automatically generated by pbr and is
   available in `IRONIC_BIN` directory. It should not be modified.
