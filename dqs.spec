Summary:	Distributed Queuing System
Summary(pl.UTF-8):	System Rozproszonego Kolejkowania
Name:		dqs
Version:	3.3.2
Release:	3
Group:		Applications/Networking
License:	GPL
Source0:	ftp://ftp.csit.fsu.edu/pub/dqs/DQS-%{version}.tgz
# Source0-md5:	f571710957d1ca0c821d54a43f927a33
Source1:	%{name}-PLD-%{name}.h
Source2:	%{name}-PLD-def.h
Source3:	%{name}-PLD-resolve_file
Source4:	%{name}-PLD-conf_file
#Source6:	%{name}-init
Patch0:		%{name}-DESTDIR.patch
Patch1:		%{name}-mq.patch
URL:		http://www.scri.fsu.edu/~pasko/dqs.html
BuildRoot:	%{tmpdir}/%{name}-%{version}-root-%(id -u -n)

%description
Distributed queuing system.

%description -l pl.UTF-8
System Rozproszonego Kolejkowania Zadań.

%package master
Summary:	Distributet Quening System (Master server)
Summary(pl.UTF-8):	System Rozproszonego Kolejkowania (Master server)
Group:		Applications/Networking
Requires:	%{name} = %{version}-%{release}

%description master
Distributed quening system. Master server.

%description master -l pl.UTF-8
System Rozproszonego Kolejkowania Zadań. Master server.

%prep
%setup  -q -n DQS3
cp %{SOURCE1} SRC/dqs.h
cp %{SOURCE2} SRC/def.h
%patch0 -p1
%patch1 -p1

%build
%{__make} CFLAGS="%{rpmcflags}" CC="%{__cc}"

%install
rm -rf $RPM_BUILD_ROOT
%{__make}  DESTDIR=$RPM_BUILD_ROOT installall
install -d $RPM_BUILD_ROOT%{_sysconfdir}/%{name}

install %{SOURCE3} $RPM_BUILD_ROOT%{_sysconfdir}/%{name}/resolve_file
install %{SOURCE4} $RPM_BUILD_ROOT%{_sysconfdir}/%{name}/conf_file

install -d $RPM_BUILD_ROOT%{_mandir}/man1
install MAN/man1/* $RPM_BUILD_ROOT%{_mandir}/man1

install -d $RPM_BUILD_ROOT/var/spool/%{name}/common_dir
install -d $RPM_BUILD_ROOT/var/log/%{name}
install -d $RPM_BUILD_ROOT%{_docdir}/%{name}-%{version}
install DOC/user_guide/*.html $RPM_BUILD_ROOT%{_docdir}/%{name}-%{version}

install COPYRIGHT README ChangeLog KnownBugs ReleaseNotes_3.3.1 ToDo  \
	$RPM_BUILD_ROOT%{_docdir}/%{name}-%{version}
gzip -n9  $RPM_BUILD_ROOT%{_docdir}/%{name}-%{version}/{COPYRIGHT,README,ChangeLog,KnownBugs,ReleaseNotes_3.3.1,ToDo}

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(644,root,root,755)
%attr(755,root,root) %{_bindir}/*
%attr(755,root,root) %{_sbindir}/qconf332
%attr(755,root,root) %{_sbindir}/dqs_execd332
%doc %{_mandir}/man1
%doc %{_docdir}/%{name}-%{version}
%dir /var/spool/%{name}/common_dir
%dir /var/log/%{name}
%dir %{_sysconfdir}/%{name}
%attr(640,root,root) %config(noreplace) %verify(not md5 mtime size) %{_sysconfdir}/%{name}/*

%files master
%defattr(644,root,root,755)
%attr(755,root,root) %{_sbindir}/qmaster332
