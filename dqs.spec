Summary:	Distributet Quening System
Name:		DQS
Version:	3.3.1
Release:	1
Group:		System/Administration
Copyright:	GPL
Vendor:         PLD
Source0:	ftp://ftp2.scri.fsu.edu/pub/dqs/%{name}-%{version}.tgz
URL:		http://www.scri.fsu.edu/~pasko/dqs.html
#BuildPrereq:	-
#Requires:	-
#Prereq:		-
BuildRoot:	%{tmpdir}/%{name}-%{version}-root-%(id -u -n)

%description

Distributet quening system
%prep
%setup  -q

%build
autoheader;autoconf;automake; 

LDFLAGS="-s" ; export LDFLAGS
%configure 

make

%install
rm -rf $RPM_BUILD_ROOT

gzip -9nf $RPM_BUILD_ROOT%{_infodir}/*.info* \
	$RPM_BUILD_ROOT%{_mandir}/man*/* \
	README ChangeLog 

%pre

%preun

%post

%postun

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(644,root,root,755)

%changelog
