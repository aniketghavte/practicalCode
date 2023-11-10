create(){

	echo "Enter address book name : "
	read name
	res=`ls | grep $name | wc -w`
	
	if [ $res -gt 0 ] 
	then 
		echo "File is already exists..."
		echo ""
	else
		touch $name
		echo "File is Created Successfully..."
		echo ""
	fi	
}
display(){
	echo "Enter address book name: "
	read name
	res=`ls | grep $name | wc -w`
	if [ $res -gt 0 ]
	then 
		cat $name
	else
		echo "File is not exists..."
		echo " "
	fi	
}
insert(){
	echo "Enter address book name: "
	read name
	res=`ls | grep $name | wc -w`
	if [ $res -gt 0 ]
	then 
		echo "Enter email  :  : "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ] 
		then 
			echo "This ID is already exists..."
			echo ""
		else 
			echo "Enter first name : "
			read fname
			echo "Enter last name : "
			read lname
			echo "Enter city name : "
			read city
			
			record=`echo  $fname $lname $city $email`
			echo $record >> $name
			echo "Record is inserted Successfully..."
			echo ""
		fi
	else
		echo "File is not exists..."
		echo " "
	fi	
}
modify(){
	echo "Enter address book name: "
	read name
	res=`ls | grep $name | wc -w`
	if [ $res -gt 0 ]
	then 
		echo "Enter email  :  : "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ] 
		then 
			echo "Enter Modified Data"
			echo "enter first name: "
			read fname
			echo "Enter last name: "
			read lname
			echo "Enter city name: "
			read city
			new=`echo $fname $lname $city $email`
			
			old=`cat $name | grep $email`
			sed -i s/"$old"/"$new"/g $name
			echo "Record modified Successfully..."
			echo ""
		else 
			echo "Email is not exists..."
			echo ""
		fi
	else
		echo "File is not exists..."
		echo " "
	fi	
}
delete(){
	echo "Enter address book name: "
	read name
	res=`ls | grep $name | wc -w`
	if [ $res -gt 0 ]
	then 
		echo "Enter email  :  : "
		read email
		len=`cat $name | grep $email | wc -w`
		if [ $len -gt 0 ] 
		then 
			old=`cat $name | grep $email`
			sed -i s/"$old"/""/g $name
			sed -i /^$/d $name
			echo "Record deleted Successfully..."
			echo ""
		else 
			echo "Email is not exists..."
			echo ""
		fi
	else
		echo "File is not exists..."
		echo " "
	fi	
}
while [ true ] 
do
	echo "----*----*-Operations-*----*----"
	echo ""
	echo "1.create"
	echo "2.display"
	echo "3.insert"
	echo "4.modify"
	echo "5.delete"
	echo "6.exit"
	echo "enter your choice : "
	read choice
	case $choice in
		1) create ;;
		2) display ;;
		3) insert ;;
		4) modify ;;
		5) delete ;;
		6) exit ;;
		*) echo "Enter Correct Choice..."
		  echo " "  ;;
	esac
done

