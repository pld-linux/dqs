Summary:	Distributet Quening System
Summary(pl):	System Rozproszonego Kolejkowania
Name:		dqs
Version:	3.3.2
Release:	1
Group:		Applications/Networking
Group(de):	Applikationen/Netzwerkwesen
Group(pl):	Aplikacje/Sieciowe
License:	GPL
Source0:	ftp://ftp.csit.fsu.edu:/pub/pub/dqs/DQS-%{version}.tar.gz
Source1:	%{name}-PLD-%{name}.h
Source2:	%{name}-PLD-def.h
Source3:	%{name}-PLD-resolve_file
Source4:	%{name}-PLD-Makefile
Source5:	%{name}-PLD-conf_file
Source6:	%{name}-init
Patch0:		%{name}-install.patch
URL:		http://www.scri.fsu.edu/~pasko/dqs.html
BuildRoot:	%{tmpdir}/%{name}-%{version}-root-%(id -u -n)

%description
Distributed quening system

%description -l pl
System Rozproszonego Kolejkowania Zadañ.

%prep
%setup  -q -n DQS3
cp %{SOURCE1} SRC/dqs.h
cp %{SOURCE2} SRC/def.h
cp %{SOURCE4} Makefile
%patch0 -p1

%build
%{__make}

%install
rm -rf $RPM_BUILD_ROOT

%{__make}  DESTDIR=$RPM_BUILD_ROOT installall

install %{SOURCE3} $RPM_BUILD_ROOT%{_sysconfdir}/%{name}/resolve_file
install %{SOURCE5} $RPM_BUILD_ROOT%{_sysconfdir}/%{name}/conf_file

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
%doc %{_mandir}/man1
%doc %{_docdir}/%{name}-%{version}
%dir /var/spool/%{name}/common_dir
%dir /var/log/%{name}
%attr(640,root,root) %config(noreplace) %verify(not md5 size mtime) %{_sysconfdir}/%{name}/*
