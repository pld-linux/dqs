Summary:	Distributet Quening System
Summary(pl):	System Rozproszonego Kolejkowania
Name:		dqs
Version:	3.3.2
Release:	2
Group:		Applications/Networking
Group(de):	Applikationen/Netzwerkwesen
Group(pl):	Aplikacje/Sieciowe
License:	GPL
Source0:	ftp://ftp.csit.fsu.edu/pub/dqs/DQS-%{version}.tgz
Source1:	%{name}-PLD-%{name}.h
Source2:	%{name}-PLD-def.h
Source3:	%{name}-PLD-resolve_file
Source4:	%{name}-PLD-conf_file
#Source6:	%{name}-init
Patch0:		%{name}-DESTDIR.patch
Patch1:		dqs-mq.patch
URL:		http://www.scri.fsu.edu/~pasko/dqs.html
BuildRoot:	%{tmpdir}/%{name}-%{version}-root-%(id -u -n)

%description 
Distributed quening system

%description -l pl
System Rozproszonego Kolejkowania Zadañ.

%package master
Summary:        Distributet Quening System (Master server)
Summary(pl):    System Rozproszonego Kolejkowania (Master server)
Group:		Applications/Networking
Group(de):	Applikationen/Netzwerkwesen
Group(pl):	Aplikacje/Sieciowe
Requires:       %{name} == %{verion}

%description master 
Distributed quening system. Master server.

%description -l pl master
System Rozproszonego Kolejkowania Zadañ. Master server.



%prep
%setup  -q -n DQS3
cp %{SOURCE1} SRC/dqs.h
cp %{SOURCE2} SRC/def.h
#cp %{SOURCE4} Makefile
%patch0 -p1
%patch1 -p1

%build
CFLAGS="$RPM_OPT_FLAGS" CC=gcc ; export CFLAGS CC
%{__make}

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
%attr(640,root,root) %config(noreplace) %verify(not md5 size mtime) %{_sysconfdir}/%{name}/*
%files master
%defattr(644,root,root,755)
%attr(755,root,root) %{_sbindir}/qmaster332 
