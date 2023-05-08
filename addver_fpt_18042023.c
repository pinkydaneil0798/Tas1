set_str version_script              "01.12.2021.02"
set_num number_try_script           100

set_str type_source_email  			"data_7k_addver_18042023"
set_str type_source_phone  			"data_21032023_phone"
set_str job_name           			"Tham_Test"
set_str type_proxies       			"TM"

set_num  num_get_info 0
set_str sv_service_ip "192.168.88.3"
set_str sv_mail_port  "80"
set_str proxy "install_app"
set_num counter_try_script 0
set_num counter_try_clear_app 0


set_num_rnd choose_app_random 1 3

   if cmp [choose_app_random] "1"
	 toast "KuBet"
	 set_str app_name           			"pub:JOHNNIE JASON BEZZINA"
	 set_str key_search_app             "pub:JOHNNIE JASON BEZZINA"
	 set_str key_compare_chplay          "WINTBR | BẢN CHUẨN 2023"
	 set_str key_compare_chplay_2         "WINTBR | BẢN CHUẨN 2023"  
 end_if
 
  if cmp [choose_app_random] "2"
	 toast "KuBet"
	 set_str app_name           			"pub:JOHNNIE JASON BEZZINA"
	 set_str key_search_app             "pub:JOHNNIE JASON BEZZINA"
	 set_str key_compare_chplay          "WINTBR | BẢN CHUẨN 2023"
	 set_str key_compare_chplay_2         "WINTBR | BẢN CHUẨN 2023"  
 end_if
 
 
 if cmp [choose_app_random] "3"
	 toast "KuBet"
	 set_str app_name           			"pub:JOHNNIE JASON BEZZINA"
	 set_str key_search_app             "pub:JOHNNIE JASON BEZZINA"
	 set_str key_compare_chplay          "WINTBR | BẢN CHUẨN 2023"
	 set_str key_compare_chplay_2         "WINTBR | BẢN CHUẨN 2023"   
 end_if





tag get_new_info
inc_num num_get_info
concat "num_get_info: " [num_get_info] debug_num_get_info
concat [debug_num_get_info] "/" debug_num_get_info
concat [debug_num_get_info] [number_try_script] debug_num_get_info
delay_sec 1
if cmp [num_get_info] [number_try_script]
	goto mail_fail_getbk
end_if


tag start_script

concat "Start " [type_proxies] text
concat [text] [version_script] text
delay_sec 1



inc_num counter_try_script
concat "Counter_try_script: " [counter_try_script] debug_counter_try_script
concat [debug_counter_try_script] "/" debug_counter_try_script
concat [debug_counter_try_script] [number_try_script] debug_counter_try_script
toast [debug_counter_try_script]

if gt_eq [counter_try_script] [number_try_script]
	toast "Error over time"	
	goto reboot	
end_if


delay_sec_rnd 2 3

delay_sec_rnd 1 2
ctrl_home

delay_sec_rnd 1 2
//app_open com.android.vending
app_open com.android.chrome


// check current screen

tag check_current_screen
set_num counter_check_current_screen 0
while chk_limit 60		
	inc_num counter_check_current_screen
	concat "Checking current screen:   " [counter_check_current_screen] debug_counter_check_current_screen
	concat [debug_counter_check_current_screen] "/60" debug_counter_check_current_screen
	delay_sec_rnd 1 2	

	if chk_text "Play while you wait" 0		
		if chk_text "Try again" 0
			touch_xy 800 1175
			delay_sec_rnd 2 3
			goto check_current_screen
		end_if		
	end_if


	if chk_text "Enter a phone number to get a text" 0 || chk_text "phone number to get a" 0
		toast "Enter a phone number to get a text"
		while chk_limit 20								
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=ver"				
				toast "Save infor disable to server"
				while chk_limit 20								
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=ver"				
						toast "Save install error to server"
						
						goto get_new_info
					else
						toast "Save install error to server"	
					end_if
				end_while
			else
				toast "Saving infor disable to server"		
			end_if
		end_while
		goto get_new_info
	end_if

	if chk_text "scriptctl" 0
		delay_sec_rnd 1 2
		app_open com.android.chrome
		delay_sec_rnd 4 5
		goto check_current_screen
	end_if

	if chk_text "Choose an account" 0
		toast "Choose an account"
		touch_xy 760 1340
		delay_sec_rnd 2 3
		goto reboot
	end_if
	
	if chk_text "To help keep your account safe" 0
		toast "Verify it's you"
		touch_xy 760 1340
		delay_sec_rnd 2 3
		goto reboot
	end_if

	

	if chk_text "Check your device" 0 && chk_text "Resend it" 0
		toast "Get code number"
		delay_sec_rnd 2 3		
		while chk_limit 20								
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=ver"				
				toast "Save infor disable to server"
				while chk_limit 20								
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=ver"				
						toast "Save install error to server"
						
						goto get_new_info
					else
						toast "Save install error to server"	
					end_if
				end_while
			else
				toast "Saving infor disable to server"		
			end_if
		end_while
		goto reboot		
	end_if


	if chk_text "Do you have your phone" 0
		toast "Do you have your phone"
		delay_sec_rnd 2 3	
		while chk_limit 20								
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=ver"				
				toast "Save infor disable to server"
				while chk_limit 20								
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=ver"				
						toast "Save install error to server"
						
						goto get_new_info
					else
						toast "Save install error to server"	
					end_if
				end_while
			else
				toast "Saving infor disable to server"		
			end_if
		end_while
		goto reboot	
	end_if

	if chk_text "Open Movies app" 0 || chk_text "Open Books app" 0 || chk_text "Impressum" 0
		delay_sec_rnd 2 3
		ctrl_back
		delay_sec_rnd 2 3
		goto check_current_screen
	end_if

	if chk_text "Share apps with Nearby Share" 0 || chk_text "Play while you wait" 0
		delay_sec_rnd 2 3
		touch_xy 743 1181
		delay_sec_rnd 2 3
		goto check_current_screen
	end_if

	if chk_text "Tap Yes on your phone or tablet" 0
		delay_sec_rnd 2 3
		toast "error email"
		goto get_new_info
	end_if

	if chk_text "You can choose additional search services" 0
		touch_text "No thanks" 0
		delay_sec_rnd 2 3
	end_if

	if chk_text "You can choose additional web browsers for" 0
		touch_text "No thanks" 0
		delay_sec_rnd 2 3
	end_if

	if chk_text "About Google Play" 0 
		ctrl_back
		delay_sec_rnd 2 3
		goto check_current_screen
	end_if
	if chk_text "Want to stay in the loop" 0
		if chk_text "Yes, I'm in" 1
			touch_text "Yes, I'm in" 1
			delay_sec_rnd 2 3
			goto check_current_screen
		end_if	
	end_if	
	if chk_text "Introducing Google Play Points" 0 || chk_text "Try Google Play" 0		
		if chk_text "Not now" 1
			touch_text "Not now" 1
			delay_sec 4 
			goto check_current_screen
		end_if		
	end_if	

	if chk_text "Facebook" 0 
		goto start_download_app
	end_if

	if chk_text "Search for apps & games" 0
		goto screen_login_done
	end_if
	
	
	if chk_text "Browse faster" 0		
		goto screen_browse_faster
	end_if

	
    if chk_text "Sign in to find the latest Android apps" 0
        goto screen_turn_on_sync
    end_if

	if chk_text "Accept & continue" 0		
		goto screen_welcome_to_chrome
	end_if	

	if chk_text "Turn on sync?" 0		
		goto screen_turn_on_sync
	end_if
	if chk_text "We publish the Google Terms of Service" 0
		touch_text "I agree" 1
		delay_sec_rnd 1 2

		goto check_current_screen
	end_if

	if chk_text "Verify your phone number so Google" 0
		touch_text "Cancel" 1
		delay_sec_rnd 1 2
		delay_sec_rnd 2 3
		goto check_current_screen
	end_if
	
	
	
	if chk_text "Welcome to your new account" 0
		delay_sec_rnd 1 2
		swipe_xy 820 1479 up  820 407
				delay_sec_rnd 1 2
		swipe_xy 820 1479 up  820 407
				delay_sec_rnd 1 2
		swipe_xy 820 1479 up  820 407
		delay_sec_rnd 2 3
		touch_text "I understand" 1

		delay_sec_rnd 2 3
		goto check_current_screen
	end_if
	if chk_text "Tap to learn more about each service" 0
		if chk_text "ACCEPT" 1 
			delay_sec_rnd 1 2
			touch_text "ACCEPT" 1 
			goto check_current_screen
		end_if	
	end_if
	
	if chk_text "Confirm your recovery email" 0
		delay_sec_rnd 1 2
		//touch_text "Confirm your recovery email" 0
		if chk_text "Not now" 1
			touch_text "Not now" 1
			delay_sec 4
			delay_sec_rnd 4 5
			goto reboot
			//goto start_download_app
		end_if
		//goto screen_add_recovery
		goto check_current_screen
	end_if
	
	if chk_text "Wrong password" 0 || chk_text "Your password was changed" 0
		toast "Wrong password" 
		while chk_limit 20			
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=saipass"				
				toast "Save info wrong password to server"
				while chk_limit 20								
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=saipass"			
						toast "Save install error to server"
						
						goto get_new_info
					else
						toast "Save install error to server"	
					end_if
				end_while
			else
				toast "Saving info wrong password to server"		
			end_if
		end_while	
			
		goto reboot
	end_if
	if chk_text "Add phone number to account" 0 || chk_text "Add phone number?" 0
		delay_sec_rnd 1 2
		while chk_limit 60
			if chk_text "Skip" 1
				delay_sec_rnd 1 2
				touch_text "Skip" 1
				delay_sec_rnd 2 3
				delay_sec_rnd 1 2
				if chk_text "Turn on Backup" 1
					toast "Turn On Backup"
					touch_text "Turn on Backup" 1
				end_if
				delay_sec_rnd 2 3
				
				goto check_current_screen
			end_if
				delay_sec_rnd 1 2
				swipe_xy 726 1693 up 1200 500
			delay_rnd 200 300
		end_while
		goto clear_app
	end_if

	if chk_text "Never lose your contacts" 0
		toast "Never lose your contacts"
		delay_sec_rnd 2 3
		if chk_text "Turn on Backup" 1
					toast "Turn On Backup"
					touch_text "Turn on Backup" 1
				end_if
				delay_sec_rnd 2 3
		goto check_current_screen
	end_if

	if chk_text "Try again later or go to" 0
		toast "Couldn't sign you in"
		while chk_limit 20								
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=disb"				
				toast "Save infor disable to server"
				while chk_limit 20								
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=disb"				
						toast "Save install error to server"
						goto get_new_info
					else
						toast "Save install error to server"	
					end_if
				end_while
			else
				toast "Saving infor disable to server"		
			end_if
		end_while
		goto reboot	
	end_if


	if chk_text "Your account has been disabled" 0
		toast "Account disabled"
		while chk_limit 20								
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=dis"				
				toast "Save infor disable to server"
				while chk_limit 20								
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=dis"				
						toast "Save install error to server"
						 
						goto get_new_info
					else
						toast "Save install error to server"	
					end_if
				end_while
			else
				toast "Saving infor disable to server"		
			end_if
		end_while
		goto reboot	
	end_if


	if chk_text "Change password" 0					
		goto change_password
	end_if

	if chk_text "Something went wrong" 0
		goto clear_app
	end_if
	
end_while
goto clear_app
 
tag screen_browse_faster
// screen browse faster chrome
while chk_limit 60		
	if chk_text "Next" 0
		delay_sec_rnd 1 2	
		touch_text "Next" 0	
		goto screen_turn_on_sync
	else
		toast "wait screen browse faster chrome"
	end_if
end_while
goto clear_app



tag screen_checking_info
set_num counter_check_info 0
while chk_limit 60	
	if chk_text "with your Google Account" 0 
					if server_data_get ""
						toast "get resource success"
					else
						toast "get resource failed"
						delay_sec_rnd 2 3
						toast "try to get resource"
						if server_data_get ""
							toast "get resource success"
						else
							toast "get resource failed"
							delay_sec_rnd 2 3
							if server_data_get ""
								toast "get resource success"
							else
								toast "get resource failed"
							goto fail
					end_if   
						end_if 
							end_if
					toast [___id]
					toast [___id]
		touch_xy 500 850
		delay_sec_rnd 1 2
		delay_sec_rnd 2 3
		text_auto_typing 400 qwerty [email]
		delay_sec_rnd 1 2
		toast "Ctrl_back"
        ctrl_back
        delay_sec_rnd 2 3
		touch_text "Next" 1
		goto screen_type_password
	else		
		if chk_text "Couldn't sign in" 0 
			goto could_not_sign_in
		else
			if chk_text "Checking info" 0 
				inc_num counter_check_info
				concat "Checking info: " [counter_check_info] debug_counter_check_info
				concat [debug_counter_check_info] "/60" debug_counter_check_info
				delay_sec_rnd 1 2					
			else
				if chk_text "scriptctl" 0
					delay_sec_rnd 1 2
					app_open com.android.vending
					delay_sec_rnd 4 5
					goto check_current_screen
				else
					toast "Waiting for checking info"
				end_if
			end_if
		end_if	
		
	end_if	
end_while
goto clear_app


tag screen_type_password
while chk_limit 60
	if chk_text "Show password" 0 
		delay_sec_rnd 1 2
		delay_sec_rnd 2 3
		text_auto_typing 400 qwerty [password]
		delay_sec_rnd 1 2
		toast "Ctrl_back"
        ctrl_back
        delay_sec_rnd 2 3
		touch_text "Next" 1
		goto add_otp
	else
		if chk_text "Something went wrong" 0
			goto clear_app
		else
			toast "please Waiting screen password"
			if chk_text "find your Google Account" 0
				toast "Not_exit"
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=Not_exit"
					toast "Save skip this email"
					goto get_new_info
				else
					toast "Saving skip this email"	
				end_if
			end_if	
		end_if
	end_if	
end_while
goto clear_app


tag add_otp
while chk_limit 60
	if chk_text "phone number to get" 0
		if chk_text "Phone number" 0 
			delay_sec_rnd 2 3
			toast "Add phone number"
			touch_text "Phone number" 1 
			delay_sec_rnd 2 3
			text_auto_typing 400 number [info_id]
			delay_sec_rnd 2 3
			touch_xy 1280 2445
			delay_sec_rnd 2 3
		end_if
		
			while chk_limit 3
				if chk_text "Get code" 0 
				delay_sec_rnd 1 2
				toast "Get code"
				touch_text "Get code" 1 
				delay_sec_rnd 1 2
			end_if
			end_while
			delay_sec_rnd 3 4
		while chk_limit 3
		if server_data_get  "http://192.168.88.9:25000/get-otp?phone=[info_id]&pattern=G-&start=2&end=8"
		//if server_data_get  "http://65.21.51.111:25000/get-otp?phone=[info_id]&pattern=G-&start=2&end=8"
		//if server_data_get "http:/192.168.2.36:25000/get-otp?phone=[first_name]"	
			while chk_limit 2
			if chk_text "Get code" 0 
				delay_sec_rnd 1 2
				toast "Get code"
				touch_text "Get code" 1 
				delay_sec_rnd 4 5
			end_if
			end_while		
			toast [code_otp]
			touch_rnd_xyxy 340 738 1160 840	
			break
		end_if
		end_while
		delay_sec_rnd 2 3
		while chk_limit 10
		if chk_text "We sent a verification code to" 0 
			delay_sec_rnd 1 2
			toast "Enter code"
			touch_rnd_xyxy 340 738 1160 840
			delay_sec_rnd 1 2			
			text_auto_typing 400 number [code_otp]						
			delay_sec_rnd 2 3
			touch_xy 1325 2435
			delay_sec_rnd 2 3
			while chk_limit 10
				if chk_text "That verification code" 0 
				delay_sec_rnd 1 2
				toast "Ver code"
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=Add_otp_error"				
					toast "Save add otp fail to server"
					delay_sec 1
					end_if
				goto get_new_info
			  	end_if								
			end_while
			delay_sec_rnd 8 10
		end_if
		goto check_current_screen
		end_while		
		goto check_current_screen
	end_if
end_while






tag screen_add_recovery
while chk_limit 60

	if chk_text "Confirm your recovery email" 0
		delay_sec_rnd 1 2
		touch_text "Confirm your recovery email" 0
		delay_sec_rnd 2 3
		text_auto_typing 200 qwerty [email_recovery]
		delay_sec_rnd 1 2
		touch_text "Next" 1
		goto check_current_screen
	else
		toast "Please waiting screen add recovery"
	goto check_current_screen
	end_if

end_while
goto clear_app




tag could_not_sign_in
while chk_limit 60
	toast "could_not_sign_in"	
	goto clear_app
	delay_rnd 200 300
end_while


goto change_password

toast "start"
set_num_rnd key_random 1 10

concat "key_random: " [key_random] text
toast [text]

set_num_rnd number_pass_random 1000000 9999999
concat "number_pass_random: " [number_pass_random] text
toast [text]

if cmp [key_random] "1"
	set_str key_string "@#cA"
end_if
if cmp [key_random] "2"
	set_str key_string "!a$C"
end_if
if cmp [key_random] "3"
	set_str key_string "A&m"
end_if
if cmp [key_random] "4"
	set_str key_string "C(q"
end_if
if cmp [key_random] "5"
	set_str key_string "&Zt"
end_if
if cmp [key_random] "6"
	set_str key_string "JKm@"
end_if
if cmp [key_random] "7"
	set_str key_string "djf%W"
end_if
if cmp [key_random] "8"
	set_str key_string "ABEt"
end_if
if cmp [key_random] "9"
	set_str key_string "*%Qa"
end_if
if cmp [key_random] "10"
	set_str key_string "aQLm"
end_if
concat "key_string: " [key_string] text
toast [text]
set_str  new_password ""
concat "" [key_string] new_password
concat [new_password] [number_pass_random] new_password
toast [new_password] 

 while chk_limit 60
		delay_sec_rnd 2 3
		text_auto_typing 400 qwerty [new_password]
		delay_sec_rnd 1 2
		ctrl_back
		touch_xy 400 1600
		delay_sec_rnd 2 3
		text_auto_typing 400 qwerty [new_password]
		delay_sec_rnd 1 2
		ctrl_back
		delay_sec_rnd 1 2
		touch_text "Next" 0
		goto screen_after_change_password
end_while
goto reboot


tag screen_after_change_password
while chk_limit 60
	if chk_text "Never lose your contacts" 0
		touch_xy 700 2400
		touch_text "Don't turn on" 0
		delay_sec_rnd 2 3
		goto check_current_screen
	else
		toast "Please waiting change new password"
		while chk_limit 20								
			if server_data_get [link_api_post_email_change_pass]				
				toast "Save new password to server"
				goto check_current_screen
			else
				toast "Saving new password to server"		
			end_if
		end_while	
	end_if	
end_while	
goto clear_app


 tag screen_turn_on_sync
while chk_limit 60	
	if chk_text "Add account" 1
	    delay_sec_rnd 1 2
		touch_text "Add account" 1			 
		goto screen_checking_info
	else
		if chk_text "Search for apps & games" 0
			toast "install_app" 0
			goto screen_login_done
		end_if
	end_if
	
	if chk_text "Sign in" 1
	    delay_sec_rnd 1 2
		touch_text "Sign in" 1			 
		goto screen_checking_info
	else
		if chk_text "Search for apps & games" 0
			toast "install_app" 0
			goto screen_login_done
		end_if
	end_if
	
		if chk_text "Yes, I'm in" 1
			touch_text "Yes, I'm in" 1
			delay_sec_rnd 2 3
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=Add_otp_OK"				
					toast "Save add otp done to server"
					delay_sec 1
			  	end_if
			if server_data_get 			"https://5schanger.com:34443/addmail?mail=[email]&pass=[password]&recovery=[email_recovery]&type=vn&proxy=tm"
			delay_sec 1
			delay_sec 1
			end_if
			delay_sec_rnd 12 20
			goto reboot
			//goto start_download_app
		end_if					

	
	toast "wait screen turn on sync"	
end_while
goto clear_app




tag screen_login_done
while chk_limit 60
	while chk_limit 20
			if server_data_get 			"https://5schanger.com:34443/addmail?mail=[email]&pass=[password]&recovery=[email_recovery]&type=vn&proxy=tm"
			delay_sec 1
			delay_sec 1
			end_if
		if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=[type_proxies]"				
			toast "Save info good to server_begin"
				if server_data_get "http://127.0.0.1:9466/getinfoid"
					delay_sec_rnd 1 2
					toast [__infoid]
                    delay_sec_rnd 2 3
                     

					if server_data_get "http://192.168.2.6:9300/savemail?infoid=[__infoid]&mail=[email]&password=[password]&mail_resource=[type_source_email]&d1=[type_proxies]"
						delay 100
						toast "Save email to server ok"
					end_if			
				end_if

			delay_sec_rnd 2 3 			
			while chk_limit 20								
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=[type_proxies]"		
					toast "Save info good to server"
					if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
		    	        delay 100
		             end_if
					delay_sec_rnd 2 3 	
					//goto add_recovery_email
					goto reboot
					//goto start_download_app
				else
					toast "Saving info fail "		
				end_if
			end_while
			goto reboot
		else
			toast "Saving info good to server_end"	
			goto reboot
			//goto start_download_app		
		end_if
	end_while	
	toast "in screen_login_done"
end_while
goto clear_app



tag add_recovery_email

toast "add_recovery_email"

set_num counter_add_recovery_email 0
while chk_limit 100

     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
			goto add_recovery_email
         end_if        
     end_if
	  touch_xyxy 444 152 972 209
	  delay_sec_rnd 2 3
	if chk_text "Search or type web address" 0
		delay_sec_rnd 1 2
		touch_text "Search or type web address " 0
		delay_sec_rnd 7 8
		text_auto_typing 400 qwerty "https://myaccount.google.com/recovery/email"
		// if text_set "https://myaccount.google.com/recovery/email"
			delay_sec_rnd 2 3
            touch_xyxy 1270 2390 1390 2470
			while chk_limit 60
                 if !chk_running com.android.chrome
                        delay_sec_rnd 2 3
                        if app_open com.android.chrome
                            delay_sec_rnd 3 4
                            goto add_recovery_email
                        end_if        
                end_if
				//  if chk_text "https://myaccount.google.com/recovery/email" 0
					delay_sec_rnd 2 3
					//touch_text "https://myaccount.google.com/recovery/email" 0
					// touch_xyxy 1270 2390 1390 2470
					goto screen_password_when_add_recovery
				//  else
					delay_sec_rnd 1 2
				//  end_if
				
			end_while
		// 	goto clear_app
		// end_if
	else
		
        inc_num counter_add_recovery_email
         if !chk_running com.android.chrome
                delay_sec_rnd 2 3
                if app_open com.android.chrome
                    delay_sec_rnd 5 6
                    if chk_text "To continue," 0
			          goto screen_password_when_add_recovery
		            end_if
                    if chk_text "Recovery email" 0 
                        goto screen_type_email_recovery
                    end_if
             end_if        
        end_if
		if chk_text "Something went wrong" 0
			delay_sec_rnd 1 2
			goto reboot
		else
			if chk_text "You're not signed in" 0
				delay_sec_rnd 1 2
				goto reboot
			else
                
				if cmp [counter_add_recovery_email] "40"
                    delay_sec_rnd 1 2
                     if chk_text "To continue," 0
			            goto screen_password_when_add_recovery
		            end_if
				else
					if cmp [counter_add_recovery_email] "60"
						delay_sec_rnd 1 2
						swipe_xy 1200 500 down 726 1693
					else
                        if cmp [counter_add_recovery_email] "80"
                             delay_sec_rnd 2 3
                             touch_xyxy 444 152 972 209 
                             delay_sec_rnd 2 3
							 goto add_recovery_email
                        end_if
                            if chk_text "Wrong password" 0 
                                inc_num counter_wrong_password_login
                                if cmp [counter_wrong_password_login] "2"
                                    goto reboot
                                else
                                    delay_sec_rnd 1 2
                                    ctrl_back
                                    delay_sec_rnd 2 3
                                    goto screen_password_when_add_recovery	
                                end_if
                                
                            else	
                                concat "Waiting load new screen recovery email:   " [counter_add_recovery_email] debug_counter_add_recovery_email
                                concat [debug_counter_add_recovery_email] "/60" debug_counter_add_recovery_email
                                toast  [debug_counter_add_recovery_email]		
                            end_if
					end_if
				end_if
				
			end_if
		end_if
	end_if
	delay_rnd 200 300
end_while
goto reboot



tag screen_password_when_add_recovery
toast "screen_password_when_add_recovery"
set_num counter_wait_load_page_add_recovery 0
while chk_limit 100
	inc_num counter_wait_load_page_add_recovery
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
            goto screen_password_when_add_recovery
         end_if        
     end_if
	if chk_text "Forgot password" 0
		if chk_text "To continue," 0
			delay_sec_rnd 1 2
			delay_sec_rnd 1 2
			touch_xy 439 1115
			delay_sec_rnd 1 2
			toast [gender]
			text_auto_typing 400 qwerty [gender]
			delay_sec_rnd 1 2
			ctrl_back
			goto screen_result_add_password_recovery
		else
			delay_sec_rnd 1 2
			touch_xy 439 950
			ctrl_back
			goto screen_result_add_password_recovery
		end_if
	else
		if chk_text "You have security" 0
			delay_sec_rnd 1 2
			goto you_have_security_recommendations
		else			
			if chk_text "To review and adjust your security settings" 0
				if chk_text "Sign in" 0
					delay_sec_rnd 1 2
					touch_text "Sign in" 0
					delay_sec_rnd 2 3
					goto you_have_security_recommendations
				end_if
			else	
				if chk_text "Sign out and turn off sync" 0
					delay_sec_rnd 1 2
					goto fail
				else
					if chk_text "SELECT ALL" 0 
						delay_sec_rnd 1 2
						ctrl_back
					else					
						concat "Waiting load page email recovery:   " [counter_wait_load_page_add_recovery] debug_counter_wait_load_page_add_recovery
						concat [debug_counter_wait_load_page_add_recovery] "/100" debug_counter_wait_load_page_add_recovery
						toast   [debug_counter_wait_load_page_add_recovery]

                        if cmp [counter_wait_load_page_add_recovery] "15"
						    if chk_text "Search or type web address" 0
                                delay_sec_rnd 2 3
                                goto  add_recovery_email
                            end_if
						end_if

						if cmp [counter_wait_load_page_add_recovery] "20"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "30"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "40"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "50"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "60"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "70"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "80"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "90"
							delay_sec_rnd 1 2
							swipe_xy 1200 500 down 726 1693
							delay_sec_rnd 2 3
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "100"
                            delay_sec_rnd 2 3
                             touch_xyxy 444 152 972 209 
                             delay_sec_rnd 2 3
							goto add_recovery_email
						end_if

					end_if
				end_if
			end_if
		end_if
	end_if
end_while
goto reboot


tag you_have_security_recommendations
toast "you_have_security_recommendations"
while chk_limit 60
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
            goto you_have_security_recommendations
         end_if        
     end_if
	if chk_text "Recovery email" 0
		delay_sec_rnd 1 2
		touch_text "Recovery email" 0
		goto screen_password_when_add_recovery			
	else
		if chk_text "Signed in to Google as" 0
			// toast "Signed in to Google as"
			// toast "back"
			// ctrl_back
			// delay_sec_rnd 2 3
			// toast "refresh page"
			// swipe_xy 1200 500 down 726 1693
			// delay_sec_rnd 2 3
			// toast "goto screen_password_when_add_recovery"
			// goto screen_password_when_add_recovery	
			goto fail
		else
			delay_sec_rnd 1 2
			swipe_xy 726 1693 up 1200 500
		end_if
	end_if		
end_while
goto reboot



tag screen_result_add_password_recovery
toast "screen_result_add_password_recovery"
while chk_limit 60
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
            goto screen_result_add_password_recovery
         end_if        
     end_if
	if chk_text "Next" 0
		touch_text "Next" 0
		while chk_limit 60
			goto screen_type_email_recovery
			delay_rnd 200 300
		end_while
	else
		delay_sec_rnd 1 2
	end_if
	delay_rnd 200 300
end_while
goto reboot


tag screen_type_email_recovery
toast "screen_type_email_recovery"
set_num counter_wait_load_page 0

while chk_limit 100
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
             if chk_text "To continue," 0
			    goto screen_password_when_add_recovery
		    end_if 
         end_if        
     end_if
	if chk_text "Recovery email" 0
		delay_sec_rnd 1 2		
	//	swipe_xyxy 145 1260 145 1260 1000
		delay_sec_rnd 1 2	
		touch_xy 617 1555
	    delay_sec_rnd 4 5				
		// touch_xy 617 1555
		// delay_sec_rnd 3 4
		delay_sec_rnd 2 3
		touch_xy 118 2244
		delay_sec_rnd 2 3
		text_auto_typing 400 qwerty [email_recovery]
		delay_sec_rnd 1 2
		ctrl_back
		while chk_limit 60
            if !chk_running com.android.chrome
                delay_sec_rnd 2 3
                if app_open com.android.chrome
                    delay_sec_rnd 5 6
                    if chk_text "To continue," 0
			          goto screen_password_when_add_recovery
		            end_if
                    if chk_text "Recovery email" 0 
                        goto screen_type_email_recovery
                    end_if
                end_if        
            end_if
            
			if chk_text "Verify" 0 
				touch_text "Verify" 0
				goto screen_after_type_email_recovery					
			else
				if chk_text "Next" 0
					touch_text "Next" 0
					goto screen_after_type_email_recovery
				else
					delay_sec_rnd 1 2
				end_if
			end_if
			delay_sec_rnd 1 2
		end_while
		goto add_otp
		//goto reboot
	else
		inc_num counter_wait_load_page
         if !chk_running com.android.chrome
                delay_sec_rnd 2 3
                if app_open com.android.chrome
                    delay_sec_rnd 5 6
                    if chk_text "To continue," 0
			          goto screen_password_when_add_recovery
		            end_if
                    if chk_text "Recovery email" 0 
                        goto screen_type_email_recovery
                    end_if
             end_if        
        end_if
		if chk_text "Something went wrong" 0
			delay_sec_rnd 1 2
			goto reboot
		else
			if chk_text "You're not signed in" 0
				delay_sec_rnd 1 2
				goto reboot
			else
                
				if cmp [counter_wait_load_page] "20"
                    delay_sec_rnd 1 2
                     if chk_text "To continue," 0
			            goto screen_password_when_add_recovery
		            end_if
				else
					if cmp [counter_wait_load_page] "40"
						delay_sec_rnd 1 2
						swipe_xy 1200 500 down 726 1693
					else
                        if cmp [counter_wait_load_page] "60"
                            delay_sec_rnd 1 2
						    swipe_xy 1200 500 down 726 1693
                        else
                            if cmp [counter_wait_load_page] "80"
                                delay_sec_rnd 1 2
						         swipe_xy 1200 500 down 726 1693
                            else
                                if cmp [counter_wait_load_page] "100"
                                    delay_sec_rnd 1 2
						             ctrl_home 
                                else    
                                    if chk_text "Wrong password" 0 
                                        inc_num counter_wrong_password_login
                                        if cmp [counter_wrong_password_login] "2"
                                            goto reboot
                                        else
                                            delay_sec_rnd 1 2
                                            ctrl_back
                                            delay_sec_rnd 2 3
                                            goto screen_password_when_add_recovery	
                                        end_if
                                        
                                    else	
                                        concat "Waiting load new screen recovery email:   " [counter_wait_load_page] debug_counter_wait_load_page
                                        concat [debug_counter_wait_load_page] "/100" debug_counter_wait_load_page
                                        toast  [debug_counter_wait_load_page]		
                                    end_if
                                end_if
                            end_if
                         end_if   
					end_if
				end_if
				
			end_if
		end_if
	end_if
	delay_rnd 200 300
end_while
goto reboot


tag screen_after_type_email_recovery
toast "screen_after_type_email_recovery"
set_num counter_wait_done_email_recovery 0
while chk_limit 100
	inc_num counter_wait_done_email_recovery
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
         end_if        
     end_if
    if chk_text "Next" 0
		touch_text "Next" 0
    end_if
	if chk_text "Verify your recovery email" 0
		while chk_limit 15
            if !chk_running com.android.chrome
                delay_sec_rnd 2 3
                if app_open com.android.chrome
                    delay_sec_rnd 5 6
                end_if        
             end_if			
			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&success_add_recovery_mail=1"
				toast "Save recovery ok to server"
				if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
		    	        delay 100
		             end_if
					 toast "REBOOT"
				goto reboot
			else
				toast "fail"
				delay_sec_rnd 1 2
			end_if
		end_while
		goto reboot
	else
		if chk_text "To continue," 0
			goto screen_password_when_add_recovery
		else 
			if chk_text "complete this action" 0
				delay_sec_rnd 1 2
				swipe_xy 1200 500 down 726 1693
			else
				if gt_eq [counter_wait_done_email_recovery] 40 
					delay_sec_rnd 1 2
					swipe_xy 1200 500 down 726 1693
				    delay_sec_rnd 1 2
					delay_sec_rnd 4 5
					goto screen_type_email_recovery
				else
					concat "case After verify recovery email:   " [counter_wait_done_email_recovery] debug_counter_wait_done_email_recovery
					concat [debug_counter_wait_done_email_recovery] "/100" debug_counter_wait_done_email_recovery
					toast [debug_counter_wait_done_email_recovery]
					if cmp [counter_wait_done_email_recovery] "50"
						delay_sec_rnd 1 2
						swipe_xy 1200 500 down 726 1693
					end_if

				end_if
			end_if	
		end_if
	end_if
end_while
goto reboot


tag change_password
toast "change_password"
set_num counter_wait_load_page_changepass 0
set_num counter_changing_your_password 0
while chk_limit 100
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
			touch_xyxy 444 152 972 209
			 delay_sec_rnd 1 2
            goto change_password
         end_if        
     end_if
	 delay_sec_rnd 2 3
    //  if chk_text "Next" 0
	// 	touch_text "Next" 0
    // end_if
        delay_sec_rnd 3 4
         
         delay_sec_rnd 1 2
        if chk_text "Search or type web address" 0
             delay_sec_rnd 1 2
            toast "Search or type web address"
			touch_text "Search or type web address" 0
			#delay_sec_rnd 1 2
			#touch_text "Search or type web address" 0
			delay_sec_rnd 4 5
             text_auto_typing 300 qwerty "https://myaccount.google.com/signinoptions/password"
             delay_sec_rnd 2 3
             touch_xyxy 1270 2390 1390 2470
             delay_sec_rnd 3 4
             while chk_limit 50
                if !chk_running com.android.chrome
                    delay_sec_rnd 2 3
                    if app_open com.android.chrome
                        delay_sec_rnd 5 6
						touch_xyxy 444 152 972 209
                        goto change_password
                    end_if        
                end_if
                if chk_text "Forgot password" 0
                    toast "Forgot password"
                    delay_sec_rnd 4 5
                    touch_xyxy 150 1070 300 1150
                    delay_sec_rnd 4 5
                    text_auto_typing 300 qwerty [password]
                    delay_sec_rnd 1 2
                    touch_xyxy 500 1350 700 1420
                    delay_sec_rnd 1 2
					 if chk_text "Next" 0
						touch_text "Next" 0
  					  end_if    
                    delay_sec_rnd 3 4
					if chk_text "Your password was changed" 0
						if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&proxyname=changed_password_success_TMproxy" 
         					toast "Save mail changed password to server"
							 goto reboot
						end_if
					end_if
                    while chk_limit 50
                        if !chk_running com.android.chrome
                            delay_sec_rnd 2 3
                            if app_open com.android.chrome
                                delay_sec_rnd 5 6
								if chk_text "Forgot password" 0
									delay_sec_rnd 1 2
									touch_xyxy 444 152 972 209
									delay_sec_rnd 1 2
            					 	goto change_password
            					 end_if 
                            end_if        
                        end_if
                        if chk_text "Changing your password" 0
                            delay_sec_rnd 5 6
                            if touch_text "New password" 0
                                delay_sec_rnd 2 3
                                text_auto_typing 300 qwerty [gender]
                                delay_sec_rnd 1 2
                                touch_xyxy 1270 2390 1390 2470
                                delay_sec_rnd 5 6
                                text_auto_typing 300 qwerty [gender]
                                delay_sec_rnd 2 3 
                                touch_xyxy 1270 2390 1390 2470
                                delay_sec_rnd 2 3
                                goto Password_changed_successfully
                            end_if
                        else
                            inc_num counter_changing_your_password
                            concat "Waiting_change_passsword:   " [counter_changing_your_password] debug_counter_changing_your_password
                            concat [debug_counter_changing_your_password] "/50" debug_counter_changing_your_password
                            toast  [debug_counter_changing_your_password]

                             if cmp [counter_wrong_password_login] "30"
                                 delay_sec_rnd 1 2
                           		 swipe_xy 1200 500 down 726 1693
                             end_if
							   if chk_text "Search or type web address" 0
                               		delay_sec_rnd 2 3
                               		goto  change_password
                           		end_if
								 if chk_text "Forgot password" 0
									  delay_sec_rnd 1 2
									   touch_xyxy 444 152 972 209
									   delay_sec_rnd 1 2
            							 goto change_password
           						 end_if

                        end_if 
                        delay_sec_rnd 1 2
                    end_while
                else
                    inc_num counter_wait_load_page_changepass 
                    
            
                    if chk_text "Something went wrong" 0
                        delay_sec_rnd 1 2
                        goto reboot

                    else
                        if chk_text "You're not signed in" 0
                            delay_sec_rnd 1 2
                            goto reboot
                        else
                        
                        if cmp [counter_wait_load_page_changepass] "40"
                            delay_sec_rnd 1 2
                            swipe_xy 1200 500 down 726 1693
                        else
                            if cmp [counter_wait_load_page_changepass] "60"
                                delay_sec_rnd 1 2
                                swipe_xy 1200 500 down 726 1693
                            else
                                if cmp [counter_wait_load_page_changepass] "80"
                                     if chk_text "Search or type web address" 0
                               			 delay_sec_rnd 2 3
                               		 	goto  change_password
                           			 end_if
									  if chk_text "Forgot password" 0
									  delay_sec_rnd 1 2
									    touch_xyxy 444 152 972 209
									   delay_sec_rnd 1 2
            							 goto change_password
           							  end_if
                                else
                                    if cmp [counter_wait_load_page_changepass] "100"
                                        delay_sec_rnd 2 3
										 touch_xyxy 444 152 972 209
										 delay_sec_rnd 1 2
                                         goto change_password
                                    else
                                        if chk_text "Wrong password" 0 
                                            inc_num counter_wait_load_page_changepass
                                            if cmp [counter_wait_load_page_changepass] "2"
                                                goto reboot
                                            else
                                                delay_sec_rnd 1 2
                                                ctrl_back
                                                delay_sec_rnd 2 3
                                                goto screen_password_when_add_recovery	
                                            end_if
                                            
                                        else	
                                            concat "Waiting change passsword:   " [counter_wait_load_page_changepass] debug_counter_wait_load_page_changepass
                                            concat [debug_counter_wait_load_page_changepass] "/100" debug_counter_wait_load_page_changepass
                                            toast  [debug_counter_wait_load_page_changepass]		
                                        end_if
                                    end_if
                                end_if
                            end_if
                        end_if
                        
                        end_if
                    end_if
                end_if 
             delay_sec_rnd 1 2
            end_while
        end_if
end_while
goto reboot

tag Password_changed_successfully
toast "Password_changed_successfully_addpassword"
set_num counter_Password_changed_successfully 0
while chk_limit 100
     if !chk_running com.android.chrome
         delay_sec_rnd 2 3
        if app_open com.android.chrome
            delay_sec_rnd 5 6
             if chk_text "Forgot password" 0
			 	delay_sec_rnd 1 2
				  touch_xyxy 444 152 972 209
				 delay_sec_rnd 1 2
            	 goto change_password
             end_if
              if chk_text "Changing your password" 0
			  	 delay_sec_rnd 1 2
			  	  touch_xyxy 444 152 972 209
				 delay_sec_rnd 1 2
                 goto change_password
              end_if
         end_if        
     end_if
   if chk_text "Password changed successfully" 0
      delay_sec_rnd 2 3
      touch_text "Get started" 0
      if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&proxyname=[proxy]" 
         toast "Save mail changed password to server"
         	if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[_password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
                delay 100
            end_if
            toast "add recovery email"
             goto add_recovery_email    
      else 
        
        // if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&proxyname=changed_password_success_proxy_no1" 
        //     toast "Save mail changed password to server"
        //      goto reboot
        // end_if

        
      end_if

    else 
        inc_num counter_Password_changed_successfully
         concat "Waiting_Password changed successfully:   " [counter_Password_changed_successfully] debug_counter_Password_changed_successfully
         concat [debug_counter_Password_changed_successfully] "/100" debug_counter_Password_changed_successfully
         toast  [debug_counter_Password_changed_successfully]
    end_if

     if cmp [counter_Password_changed_successfully] "20"
        delay_sec_rnd 2 3
          if chk_text "Passwords don't match." 0
            goto change_password
          end_if
     end_if

	if cmp [counter_Password_changed_successfully] "30"
         delay_sec_rnd 1 2
			swipe_xy 1200 500 down 726 1693 
    end_if
    if cmp [counter_Password_changed_successfully] "40"
         delay_sec_rnd 1 2
			swipe_xy 1200 500 down 726 1693 
    end_if
    if cmp [counter_Password_changed_successfully] "50"
         delay_sec_rnd 1 2
			  if chk_text "Changing your password" 0
			  delay_sec_rnd 1 2
			   touch_xyxy 1270 2390 1390 2470
			   delay_sec_rnd 1 2
                 goto change_password
              end_if
    end_if
    if cmp [counter_Password_changed_successfully] "70"
         delay_sec_rnd 1 2
			ctrl_home
    end_if
end_while
goto reboot

// waiting for opening chrome and touch Accept and continue
tag screen_welcome_to_chrome
while chk_limit 60	
	if chk_text "Accept & continue" 0
		delay_sec_rnd 1 2	
		touch_text "Accept & continue" 0		
		goto check_current_screen
	else
		if chk_text "Turn on sync?" 0		
			goto screen_turn_on_sync
		else
			toast "wait for open chrome"
		end_if
		
	end_if
		
	delay_rnd 200 300
end_while
goto clear_app




tag clear_app
inc_num counter_try_clear_app
concat "In tag clear_app:   " [counter_try_clear_app] debug_counter_try_clear_app
toast [debug_counter_try_clear_app]
if gt_eq [counter_try_clear_app] [number_try_script]
	toast "Over number clear_app - reboot"	
	goto reboot
end_if


ctrl_recents 
delay_sec_rnd 1 2
while chk_limit 60			
	if chk_text "CLEAR ALL" 0
		delay_sec_rnd 1 2	
		touch_text "CLEAR ALL" 0		
		delay_sec_rnd 2 3		
		goto start_script
	else
		if chk_text "scriptctl" 0 
			goto start_script
		else
			if chk_text "No recent items" 0
				goto start_script
			else
				delay_sec_rnd 1 2	
				swipe_xy 1200 500 down 726 1693
				swipe_xy 1200 500 down 726 1693
				swipe_xy 1200 500 down 726 1693
				swipe_xy 1200 500 down 726 1693
			end_if
		end_if
	end_if
	delay_rnd 200 300	
	goto start_script	
end_while
goto clear_app


tag mail_fail_getbk
while chk_limit 30
		delay_sec_rnd 1 2
		if server_data_get "http://127.0.0.1:9466/bkrsgmail?clear=1"
			delay 100
			toast "clear1|1"
		end_if    
		goto reboot
end_while




tag reboot
while chk_limit 5
	toast "Get new device info and reboot"
	if server_data_get "http://127.0.0.1:9466/stop"
	
	end_if

	while chk_limit 5
			
		if server_data_get "http://127.0.0.1:9466/runscript?sf=script.txt"
			toast "runscript.txt ok"
							
		else
			delay_sec_rnd 2 3
			toast "try runscript.txt"
		end_if	
		delay_sec 15
	end_while
	delay_sec_rnd 1 2
end_while
goto reboot


tag fail
toast "start tag fail "	
while chk_limit 20			
	if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&&proxyname=fail"
		toast "Save skip this email"
		goto mail_fail_getbk
	else
		toast "Saving skip this email"	
	end_if
end_while
goto mail_fail_getbk





tag start_download_app
ctrl_recents 
delay_sec_rnd 1 2
while chk_limit 5			
	if chk_text "CLEAR ALL" 1
		delay_sec_rnd 1 2	
		touch_text "CLEAR ALL" 1		
		delay_sec_rnd 2 3		
		break
	else
		delay_sec_rnd 1 2	
		swipe_xy 1200 500 down 726 1693
		swipe_xy 1200 500 down 726 1693
		swipe_xy 1200 500 down 726 1693
		swipe_xy 1200 500 down 726 1693
		
	end_if
	delay_rnd 200 300		
end_while
delay_sec_rnd 1 2
ctrl_home
delay_sec_rnd 1 2
while chk_limit 60
	toast "start_download_app"
	app_open com.android.vending
	delay_sec_rnd 4 5
	goto screen_main_chplay
end_while
goto reboot


tag screen_main_chplay
set_num counter_wait_main_chplay 0

while chk_limit 60
     if !chk_running com.android.vending
         delay_sec_rnd 2 3
        if app_open com.android.vending
            delay_sec_rnd 5 6
            goto screen_main_chplay
         end_if        
     end_if
	if chk_text "Search for apps" 0 
		toast "have search bar chplay"
		touch_text "Search for apps" 0 
		delay_sec_rnd 4 5
		text_auto_typing 400 qwerty [key_search_app]
		delay_sec_rnd 4 5
		if chk_text "scriptctl" 0 
			toast "error chplay"
			goto Search_app_to_download
		else
			touch_xy 1360 2450
		end_if	
		toast "Delay 5s"
		delay_sec 15

		goto Search_app_to_download
	else

		if chk_text "Introducing Google Play Points" 0 || chk_text "Try Google Play" 0		
			if chk_text "Not now" 1
				toast "Not Now"
				touch_text "Not now" 1
				delay_sec 4 
				goto screen_main_chplay
			end_if		
	end_if	
    
		
			if chk_text "Not now" 1
				toast "Not Now"
				touch_text "Not now" 1
				delay_sec 4 
				goto screen_main_chplay
			end_if		
	


	if chk_text "Terms of Service" 1
		toast "Accept"
		touch_text "Accept" 1
		delay_sec 4
		goto screen_main_chplay
	end_if

		if chk_text "Want to stay in the loop" 0
			if chk_text "Yes, I'm in" 1
				toast "Yes"
				touch_text "Yes, I'm in" 1
				delay_sec_rnd 2 3
				goto screen_main_chplay
			end_if	
	end_if	

		if chk_text "You can choose additional search services" 0
			toast "No thanks"
			touch_text "No thanks" 0
			delay_sec_rnd 2 3
			goto screen_main_chplay
		end_if

		if chk_text "You can choose additional web browsers for" 0
			toast "No thanks"
			touch_text "No thanks" 0
			delay_sec_rnd 2 3
			goto screen_main_chplay
		end_if
		if chk_text "Close app" 0
			ctrl_home
			delay_sec_rnd 2 3
			goto start_download_app
		end_if
		inc_num counter_wait_main_chplay
		concat "Please waiting chplay:   " [counter_wait_main_chplay] debug_counter_wait_main_chplay
		concat [debug_counter_wait_main_chplay] "/60" debug_counter_wait_main_chplay
		toast [debug_counter_wait_main_chplay]			
		if cmp [counter_wait_main_chplay] "5"
			toast "error detect chplay"
			ctrl_home
			delay_sec 4
			goto start_download_app
		end_if		
		
	end_if
end_while
goto reboot


tag Search_app_to_download
while chk_limit 60

		if !chk_running com.android.vending
         delay_sec_rnd 2 3
        if app_open com.android.vending
            delay_sec_rnd 5 6
            goto screen_main_chplay
         end_if        
     end_if
	delay_sec_rnd 1 2
	if chk_text [key_compare_chplay] 0 && chk_text [key_compare_chplay_2] 0
		touch_text [key_compare_chplay] 0 
		delay_sec_rnd 2 3
		goto screen_download		
	else
		if chk_text "scriptctl" 0
			toast "error close app chplay"
			app_open com.android.vending
			delay_sec_rnd 4 5
			goto check_current_screen
		end_if
		if chk_text [key_compare_chplay_2] 0
			touch_text [key_compare_chplay_2] 0
			delay_sec_rnd 2 3
			goto screen_download
		end_if
		toast "Swipe up"
		swipe_xy 726 1693 up 1200 500
		if chk_text "More results" 1
			toast "More results"
				delay_sec_rnd 1 2
			touch_text "More results" 1
			delay_sec_rnd 1 2
		else
			toast "not more results"
		end_if
		

	end_if
end_while
goto reboot


tag screen_download
while chk_limit 60
	if chk_text "Install" 1
		touch_text "Install" 1
		delay_sec_rnd 2 3		
		goto screen_download_done
	else
		toast "Please waiting load screen install"
		if chk_text "Pending" 0
			delay_sec_rnd 1 2
			//goto screen_download_done
			goto write_a_reviews
		else
			if chk_text "Uninstall" 0
				delay_sec_rnd 1 2
				//goto screen_download_done
				goto write_a_reviews
			end_if
		end_if
	end_if
end_while
goto reboot

tag write_a_reviews
while chk_limit 60
	if !chk_running com.android.vending
        delay_sec_rnd 2 3
		if app_open com.android.vending
            delay_sec_rnd 5 6
            //goto screen_main_chplay
        end_if        
    end_if
	delay_sec_rnd 1 2
	swipe_xy 726 1693 up 1200 800
	if chk_text "write a review" 0
		toast "write a review"
		delay_sec_rnd 1 2
		touch_text "write a review" 0
		delay_sec_rnd 1 2
		touch_xy 1176 738
		delay_sec_rnd 2 3
		text_auto_typing 400 qwerty [info_name]
		//text_set "good"
		delay_sec_rnd 2 3
		if chk_text "POST" 0
			toast "POST"
			delay_sec_rnd 1 2
			touch_text "POST" 0
		end_if
		delay_sec_rnd 3 4
		if chk_text "Done" 0
			toast "Done"
			delay_sec_rnd 1 2
			touch_text "Done" 0
		end_if
		delay_sec_rnd 5 8
		if chk_text "Done" 0
			toast "Done"
			delay_sec_rnd 1 2
			touch_text "Done" 0			
			
		end_if
		toast "Swipe up"
		delay_sec_rnd 1 2
		swipe_xy 820 1479 down  820 407
		delay_sec_rnd 1 2
		toast "Swipe up"
		swipe_xy 820 1479 down  820 407
		goto screen_download_done
	else
		
		toast "not view"
	end_if
end_while
goto screen_download_done

tag screen_download_done
while chk_limit 240
    if !chk_running com.android.vending
         delay_sec_rnd 2 3
        if app_open com.android.vending
            delay_sec_rnd 5 6
            goto screen_main_chplay
         end_if        
     end_if

	if chk_text "Pending" 0
		toast "Pending"
	else		
		if chk_text "Uninstall" 0
			toast "install done"
			while chk_limit 10								
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"				
					toast "Save install done to server"
					if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
		    	        delay 100
		             end_if
					delay_sec_rnd 2 3 
					goto reboot
				else
					toast "Saving install done to server"		

				end_if
				delay_sec_rnd 1 2
					
			end_while
			goto reboot
		else
			if chk_text "Complete account setup" 0
				if chk_text "Skip" 1
					toast "skip"
					touch_text "Skip" 1
				else
					toast "Complete account setup"					
					touch_xy 740 2450
					delay_sec 4
				end_if
			else
				if chk_text "Terms of Service" 0
					touch_text "Accept" 0
					delay_sec_rnd 2 3
				else
					if chk_text "Are you trying to sign in" 0 
						toast "Are you trying to sign in"
						while chk_limit 1								
							if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"					
								toast "Save infor disable to server"
								if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
		    	       				 delay 100
		            			end_if
								while chk_limit 1								
									if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"				
										toast "Save install error to server"
										if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
		    	       				 		delay 100
		            					end_if
										goto reboot
									else
										toast "Save install error to server"	
									end_if
								end_while
							else
								toast "Saving infor disable to server"		
							end_if
						end_while
						goto reboot	
					else
						toast "Another case"
						 delay_sec_rnd 1 2
						 if chk_text "Send feedback" 1
							toast "goto reboot"
							delay_sec_rnd 1 2
							goto reboot
						 else
						 	
						end_if
					end_if
				end_if
			end_if
		end_if
		
	end_if
end_while
goto reboot