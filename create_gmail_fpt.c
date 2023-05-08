
set_str type_source_email  "data_21042023"
set_str job_name           "Tham_test_tiktok"
set_str type_proxies       "tmproxy_getotp"

set_str sv_service_ip "192.168.2.5"
set_str sv_mail_port  "80"
set_str proxy "tm"

set_num counter_try_script 0
set_num counter_try_clear_app 0

set_num number_install 0
set_num choose_app_random  0




tag get_new_info

if server_data_get ""
	toast "get resource success"
else
	toast "get resource failed"
	delay_sec 2
	toast "try to get resource"
	if server_data_get ""
		toast "get resource success"
	else
		toast "get resource failed"
		delay_sec 2
		if server_data_get ""
			toast "get resource success"
		else
			toast "get resource failed"
			goto fail
		end_if 	
	end_if 
end_if


tag start_script

concat "Start " [type_proxies] text
concat [text] " ver 01.12.02" text
toast [job_name]

set_num counter_wrong_password_login 0

inc_num counter_try_script
concat "Counter_try_script: " [counter_try_script] debug_counter_try_script
concat [debug_counter_try_script] "/40" debug_counter_try_script
toast [counter_try_script]

if gt_eq [counter_try_script] 40
	delay_sec 1
	goto fail	
else 

end_if

delay_sec 1
ctrl_home


delay_sec 1
app_open com.android.chrome
//goto check current screen

tag check_current_screen
set_num counter_check_current_screen 0
while chk_limit 60		
	inc_num counter_check_current_screen
	if chk_text "Search or type web address" 0
		//goto add_recovery_email
		goto reboot
	end_if
	if chk_text "Accept & continue" 0		
		goto screen_welcome_to_chrome
	end_if
	if chk_text "Browse faster" 0		
		goto screen_browse_faster
	end_if
	if chk_text "Turn on sync?" 0		
		goto screen_turn_on_sync
	end_if

	if chk_text "Privacy and Terms" 0	
		goto screen_Privacy_and_Terms
	end_if

	if chk_text "Review your account info" 0		
		goto screen_review_account_info
	end_if

	if chk_text "Choose personalization settings" 0		
		goto screen_choose_personalization_setting
	end_if

	if chk_text "Something went wrong" 0
		goto clear_app
	end_if 

	if chk_text "Choose an account" 0
		delay_sec 1
		delay_sec 2
		touch_xy 670 1335
		delay_sec 1
		delay_sec 3
		goto check_current_screen
	end_if 
	if chk_text "Step 1 of 4" 0
		if chk_text "App Activity in my account" 0
			touch_text "App Activity in my account" 0
			delay_sec 3		
			while chk_limit 60
				if chk_text "Learn more about" 0
					if chk_text "Next" 1
						touch_text "Next" 1
						delay_sec 10
						goto check_current_screen
					end_if
				else
					delay_sec 1
					swipe_xy 726 1693 up 1200 500
				end_if
			end_while
			goto reboot		
		else
			delay_sec 1
		end_if
		
	end_if

	if chk_text "Step 2 of 4" 0
		if chk_text "save YouTube History in my account" 0
			touch_text "save YouTube History in my account" 0
			delay_sec 3		
			while chk_limit 60
				if chk_text "Learn more about" 0
					delay_sec 1
					swipe_xy 726 1693 up 1200 500
					if chk_text "Next" 1
						touch_text "Next" 1
						delay_sec 10
						goto check_current_screen
					end_if
				else
					delay_sec 1
					swipe_xy 726 1693 up 1200 500
				end_if
			end_while
			goto reboot		
		else
			delay_sec 1
		end_if
		
	end_if
	if chk_text "Step 3 of 4" 0
		if chk_text "Next" 1
			touch_text "Next" 1
			delay_sec 10
			goto check_current_screen					
		else
			delay_sec 1	
		end_if
		
	end_if
	if chk_text "Step 4 of 4" 0
		while chk_limit 60			
			if chk_text "Confirm" 1
				touch_text "Confirm" 1
				delay_sec 10
				goto check_current_screen				
			else
				delay_sec 1
				swipe_xy 726 1693 up 1200 500
			end_if
		end_while
		goto mail_fail_getbk
		
	end_if

	concat "Checking current screen:   " [counter_check_current_screen] debug_counter_check_current_screen
	concat [debug_counter_check_current_screen] "/60" debug_counter_check_current_screen
	delay_sec 1
end_while
goto clear_app



// waiting for opening chrome and touch Accept and continue
tag screen_welcome_to_chrome
while chk_limit 60	
	if chk_text "Accept & continue" 0
		delay_sec 1	
		touch_text "Accept & continue" 0		
		goto check_current_screen
	else
		if chk_text "Turn on sync?" 0		
			goto screen_turn_on_sync
		else
			delay_sec 1
		end_if
		
	end_if
		
	delay_rnd 200 300
end_while
goto clear_app


tag screen_browse_faster
// screen browse faster chrome
while chk_limit 60		
	if chk_text "Next" 0
		delay_sec 1
		touch_text "Next" 0	
		goto screen_turn_on_sync
	else
		if chk_text "No thanks" 0	
			delay_sec 1	
			touch_text "No thanks" 0
			goto screen_password_when_add_recovery
		else

		end_if
	end_if
	delay_sec 1
end_while
goto clear_app

tag screen_turn_on_sync
while chk_limit 60		
	if chk_text "Add account" 0
	    delay_sec 1
		touch_text "Add account" 0			 
		goto screen_checking_info
	end_if
	if chk_text "Yes, I'm in" 0
		touch_text "Yes, I'm in" 0
		    delay_sec 1
		delay_sec 2
		goto check_current_screen
	end_if
    delay_sec 1
end_while
goto clear_app


tag screen_checking_info
set_num counter_check_info 0
while chk_limit 60	
	if chk_text "with your Google Account" 0 
		set_num counter_touch_create_account 0
		set_num counter_try_touch_create_account 0
		goto page_start_create_account
	else
		if chk_text "Enter your name" 0
			delay_sec 1
			goto screen_enter_your_name
		else
			if chk_text "Couldn't sign in" 0 
				goto could_not_sign_in
			else
				if chk_text "Checking info" 0 
					inc_num counter_check_info
					concat "Checking info: " [counter_check_info] debug_counter_check_info
					concat [debug_counter_check_info] "/60" debug_counter_check_info
					delay_sec 1					
				else
					if chk_text "Close app" 0 || chk_text "Open app again" 0
						delay_sec 1
						if chk_text "Close app" 0
							touch_text "Close app" 0
						end_if
						if chk_text "Open app again" 0
							touch_text "Open app again" 0
						end_if
						delay_sec 1
						goto page_start_create_account
					else
						delay_sec 1
					end_if
				end_if
			end_if	
		end_if
	end_if	
end_while
goto clear_app



tag page_start_create_account
while chk_limit 60	
	if chk_text "For myself" 0 || chk_text "For my personal use" 0
		    delay_sec 1	
		if chk_text "For myself" 0
			touch_text "For myself" 0	
		end_if	
		if chk_text "For my personal use" 0
			touch_text "For my personal use" 0	
		end_if	
		while chk_limit 60			
			if chk_text "Enter your name" 0
				goto screen_enter_your_name

			else
				delay_sec 1	
			end_if
			
			delay_rnd 200 300
		end_while
	else
		if cmp [counter_touch_create_account] "1"
			delay_sec 1
			inc_num counter_try_touch_create_account
			concat "counter_try_touch_create_account: " [counter_try_touch_create_account] debug_counter_try_touch_create_account
			delay_sec 1
			if gt_eq [counter_try_touch_create_account] 3
				delay_sec 1				
				goto clear_app	
			else
				delay_sec 1
				touch_xy 750 1600
				delay_sec 2
				set_num counter_touch_create_account 0
			end_if
		else

		end_if
	end_if

	if chk_text "Enter your name" 0
		delay_sec 1
		goto screen_enter_your_name
	end_if

	if chk_text "Create account" 0
		delay_sec 1	
		set_num counter_touch_create_account 1
		touch_text "Create account" 0
	end_if	
	delay_sec 1	
end_while
goto clear_app




tag screen_enter_your_name

while chk_limit 30
	delay_sec 1
	touch_rnd_xyxy 107 780 1300 941
	delay_sec 1	
	delay_sec 1
	text_auto_typing 400 qwerty [first_name]
	delay_sec 1
	 touch_rnd_xyxy 126 1058 1285 1178
	// delay_sec 1	
	 delay_sec 1
	 text_auto_typing 400 qwerty [last_name]
	ctrl_back	
	delay_sec 2	
	if chk_text "Next" 0
		delay_sec 1	
		touch_text "Next" 0
		set_num counter_try_screen_birthday 0 
		
		set_num counter_load_screen_birthday 0
		while chk_limit 30
			inc_num counter_load_screen_birthday
			if chk_text "Enter your birthday and gender" 0
				goto screen_enter_your_birthday
			else
				if chk_text "Something went wrong" 0
					delay_sec 1
					goto clear_app
				else					
					concat "Waiting load screen birthday: " [counter_load_screen_birthday] debug_counter_load_screen_birthday
					concat [debug_counter_load_screen_birthday] "/30" debug_counter_load_screen_birthday
					delay_sec 1
					if cmp [counter_load_screen_birthday] "25"
						if chk_text "Enter your name" 0
							delay_sec 1
							goto screen_enter_your_name
						end_if
					end_if
				end_if
			end_if
		end_while
		delay_sec 1
		goto clear_app
	end_if
end_while
goto clear_app



tag screen_enter_your_birthday
while chk_limit 60	
	if chk_text "Enter your birthday and gender" 0 
		delay_sec 1
		delay_rnd 200 300
		delay_sec 1
		touch_rnd_xyxy 110 791 441 913		
		delay_sec 1
		touch_rnd_xyxy 170 214 1274 2443				
		delay_sec 1	
		touch_rnd_xyxy 590 780 899 945 
		delay_sec 1		
		text_auto_typing 400 number [day]		
		delay_sec 1
		touch_rnd_xyxy 985 781 1329 930
		delay_sec 1	
	//	set_num_rnd year_random 2004 2008
		text_auto_typing 400 number [year]		
		ctrl_back
		delay_sec 1
		if chk_text "Gender" 1	
			delay_sec 1
			touch_text "Gender" 1
			while chk_limit 30
				if chk_text "Female" 0 
				delay_sec 1
					touch_rnd_xyxy 151 988 1274 1473
					while chk_limit 60
						delay_rnd 200 300
						if chk_text "Next" 0
							delay_sec 1	
							touch_text "Next" 0
							set_num counter_wait_screen_choose_your_gmail 0
							goto screen_choose_your_gmail_address
						else		
							if chk_text "Female" 0 
								delay_sec 1
								touch_rnd_xyxy 151 988 1274 1473								
								if chk_text "Next" 0
									delay_sec 1	
									touch_text "Next" 0
									set_num counter_wait_screen_choose_your_gmail 0
									goto screen_choose_your_gmail_address
								end_if
							else	

							end_if
						end_if
					end_while
					goto clear_app
				else
					delay_sec 1
				end_if			
			end_while
			goto clear_app
		else

		end_if
		
	else
		inc_num counter_try_screen_birthday
		concat "Counter_try_screen_birthday: " [counter_try_screen_birthday] debug_counter_try_screen_birthday
		delay_sec 1		
		if gt_eq [counter_try_screen_birthday] 3
		    delay_sec 1			
			delay_sec 1
			touch_xy 350 1100
			while chk_limit 5
				if chk_text "Female" 0
					delay_sec 1
					touch_rnd_xyxy 151 988 1274 1473
					while chk_limit 60
						delay_rnd 200 300
						if chk_text "Next" 0
							delay_sec 1
							touch_text "Next" 0
							set_num counter_wait_screen_choose_your_gmail 0
							goto screen_choose_your_gmail_address
						end_if
					end_while
					goto clear_app						
				end_if			
			end_while				
			goto clear_app			
		else 
				
		end_if
		if chk_text "Something went wrong" 0 
			delay_sec 1
			goto start_script
		else
			if chk_text "Enter first name" 0		
				delay_sec 1
				goto screen_enter_your_name
			else
				
			end_if
		end_if
	end_if
end_while
goto clear_app


if chk_text "Gender" 1
	delay_sec 1
else
	delay_sec 1
end_if



tag screen_choose_your_gmail_address
while chk_limit 30	
	if chk_text "Choose your Gmail address" 0	
		delay_sec_rnd 2 3
		// touch_text "Create your own Gmail address" 0
		// delay_sec 1
		// delay_sec 1
		// text_auto_typing 400 qwerty [email]
        touch_xyxy 266 820 629 839
		delay_sec 1
		if get_gmail_suggest
			delay 100
			toast [email]
		end_if
		delay_sec 2
		if chk_text "Next" 0
			delay_sec 1	
			touch_text "Next" 0
			goto screen_create_a_strong_password
		end_if
	else
		if chk_text "Something went wrong" 0 
			delay_sec 1	
			goto clear_app
		else
			if chk_text "Please fill in a" 0 
			delay_sec 1
				goto screen_enter_your_birthday
			else
				if chk_text "Create a Gmail address for signing in to your" 0
					delay_sec 1	
					delay_sec 1
					text_auto_typing 400 qwerty [email]
					delay_sec 2
                     ctrl_back
					if chk_text "Next" 0
						delay_sec 1	
						touch_text "Next" 0
						goto screen_create_a_strong_password
					end_if
				else
					inc_num counter_wait_screen_choose_your_gmail
					concat "Waiting screen_choose_your_gmail " [counter_wait_screen_choose_your_gmail] debug_counter_wait_screen_choose_your_gmail
					concat [debug_counter_wait_screen_choose_your_gmail] "/30" debug_counter_wait_screen_choose_your_gmail
					delay_sec 1
					if gt_eq [counter_wait_screen_choose_your_gmail] 30		
						delay_sec 1			
						goto clear_app
					end_if
				end_if
			end_if
		end_if
		
	end_if	
end_while
goto clear_app 



tag screen_create_a_strong_password
while chk_limit 80
	if chk_text "Create a strong password" 0		
		while chk_limit 60
			delay_rnd 200 300
			if chk_text "Password" 0 
				delay_sec 1
				touch_rnd_xyxy 139 875 1311 1016
				delay_sec 2
				text_auto_typing 400 qwerty [password]
				delay_sec 1
				ctrl_back	
				if chk_text "Next" 0
					delay_sec 1
					touch_text "Next" 0
					goto screen_result_of_create_email	
				end_if
			end_if
		end_while
		goto clear_app
	else
		
		if chk_text "Something went wrong" 0
			delay_sec 1
			goto start_script
		else
			if chk_text "That username is taken" 0
				delay_sec 1
				while chk_limit 20			
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2"
						toast "Save infor error to server"
						goto get_new_info
					else
						toast "Saving infor error to server"		
					end_if
				end_while	
				goto mail_fail_getbk
			else
				delay_sec 1
			end_if
		end_if
	end_if	
end_while
goto clear_app


tag screen_result_of_create_email
while chk_limit 60	
	if chk_text "Get a verification code sent to your phone" 0
			toast "add phone number get to code"
			touch_xyxy 506 815 1139 889
			if chk_text "84" 1
				toast "get_new_info"
				goto get_new_info
			end_if
			delay_sec_rnd 1 2
			text_auto_typing 300 number [info_id]
			
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&proxyname=Add number ok"		
					end_if
					
			delay_sec_rnd 1 2
			while chk_limit 2
				if chk_text "Next" 1
					toast "Next"
					touch_text "Next" 1
					break
				end_if
			end_while
			delay_sec_rnd 1 2
			while chk_limit 5
			if chk_text "This phone number cannot be used for" 0 || chk_text "This phone number format is not recognized" 0 || chk_text "This phone number has been used" 0
					toast "This phone number cannot be used for"
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&proxyname=This phone number cannot be used for verication"
						delay_sec 1
						goto get_new_info
					else
						delay_sec 1		
					end_if
				end_if
			end_while
		delay_sec 1
		while chk_limit 5
					if chk_text "Wrong number of digits" 0 || chk_text "Wrong code" 0
					toast "This phone number cannot be used for"
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&proxyname=Cannot get otp"
						delay_sec 1
						goto get_new_info
					else
						delay_sec 1		
					end_if
				end_if
		end_while
		delay_sec 1

		while chk_limit 10
            delay_sec_rnd 2 3
            if chk_text "Enter the code" 0	
                toast "code"
                while chk_limit 5
				
				if server_data_get  "http://192.168.2.36:25000/get-otp?phone=[info_id]&pattern=G-&start=2&end=8"
					//if server_data_get "http://192.168.2.36:25000/get-otp?phone=[info_id]&pattern=Google&start=2&end=8"
                    //if server_data_get "http://192.168.2.36:25000/get-otp?phone=[info_id]"
					
                        toast [info_id]
                        delay_sec_rnd 2 3
                        toast "get_otp"
                        toast [code_otp]
                        break
                    else
                        delay_sec 5
                        toast "fail khong the lay code "
                    end_if
                end_while
                    delay_sec_rnd 1 2
                    touch_xyxy 471 906 1100 968
                    text_auto_typing 300 number [code_otp]
                    delay_sec_rnd 2 3
                    if chk_text "Next" 1
                        delay_sec_rnd 1 2
                        touch_text "Next" 1
                        delay_sec_rnd 3 4
                        break
                    end_if
            else
				
				if chk_text "This phone number cannot be used for" 0 || chk_text "Wrong number of digits" 0 || chk_text "Wrong code" 0 || chk_text "This phone number format is not recognized" 0 || chk_text "Sorry" 0
					toast "Cannot get otp"
					delay_sec_rnd 1 2
					touch_text "Get new code" 1
					
					if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2&proxyname=Cannot get otp"
						delay_sec 1
					else
						delay_sec 1		
					end_if
                                goto get_new_info
				end_if
               delay_sec_rnd 1 2


            end_if
    
	    end_while
    end_if

	// 	if server_data_get ""
	// 		toast "get resource success"
	// 	else
	// 		toast "get resource failed"
	// 		delay_sec 2
	// 		toast "try to get resource"
	// 		if server_data_get ""
	// 			toast "get resource success"
	// 		else
	// 			toast "get resource failed"
	// 			delay_sec 2
	// 			if server_data_get ""
	// 				toast "get resource success"
	// 			else
	// 				toast "get resource failed"
	// 				goto fail
	// 			end_if 	
	// 		end_if 
	// 	end_if	
	// 	goto clear_app
	// end_if


	if chk_text "Add phone number to account" 0 || chk_text "Add phone number?" 0 || chk_text "Add number for account" 0
		delay_sec 1
		while chk_limit 60
			if chk_text "Skip" 1
			    delay_sec 1
				touch_text "Skip" 1
				goto check_current_screen
			end_if
				delay_sec 1
				swipe_xy 726 1693 up 1200 500
			delay_rnd 200 300
		end_while
		goto clear_app
	end_if

	if chk_text "Something went wrong" 0
		if chk_text "Next" 0
			delay_sec 1
			touch_text "Next" 0
			goto clear_app
		end_if
	end_if 
	
	if chk_text "Tap to learn more about each service" 0
		delay_sec 1
		if chk_text "ACCEPT" 1 
			delay_sec 1
			touch_text "ACCEPT" 1 
			goto screen_turn_on_sync_after_email_done
		else 
			delay_sec 1
		end_if	
	end_if	

	if chk_text "test Your account" 0
		delay_sec 1
		goto mail_fail_getbk
	end_if

	if chk_text "Get help from a parent" 0
		delay_sec 1
		goto mail_fail_getbk
	end_if


	delay_sec 1		
end_while
goto clear_app


tag screen_turn_on_sync_after_email_done
while chk_limit 60	
	if chk_text "Sync your passwords, history" 0
		if chk_text "Yes, I'm in" 0
			touch_text "Yes, I'm in" 0
			delay_sec 1
			delay_sec 2
			
			if server_data_get 			"https://5schanger.com:34443/addmail?mail=[email]&pass=[password]&recovery=[email_recovery]&type=vn&proxy=tm"
			delay_sec 1
			delay_sec 1
			end_if

			if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&success_add_recovery_mail=0&proxyname=[type_proxies]&email=[email]"
				delay_sec 1
				delay_sec 1
			end_if

            delay_sec 5
		    if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&clear=1"
		    	delay 100
		    end_if

			if server_data_get "http://127.0.0.1:9466/getinfoid"
				delay_sec 1
				delay_sec 1
				if server_data_get "http://192.168.5.5:9100/savemail?infoid=[__infoid]&mail=[email]&password=[password]&mail_resource=[type_source_email]&d1=[type_proxies]"
					delay 100
					delay_sec 1
			  	end_if
			end_if
			//goto reboot  /////////////////////////////////done
			goto start_download_app
		else
			delay_sec 1
		end_if
	else
		delay_sec 1
	end_if
end_while
goto reboot




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
	if chk_text "Search or type web address" 0
		delay_sec 1
		touch_text "Search or type web address " 0
		delay_sec_rnd 7 8
		
		delay_sec 2
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
					delay_sec 3
					//touch_text "https://myaccount.google.com/recovery/email" 0
					// touch_xyxy 1270 2390 1390 2470
					goto screen_password_when_add_recovery
				//  else
					delay_sec 1
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
			delay_sec 1
			 goto reboot
		else
			if chk_text "You're not signed in" 0
				delay_sec 1
				 goto reboot
			else
                
				if cmp [counter_add_recovery_email] "40"
                    delay_sec_rnd 1 2
                     if chk_text "To continue," 0
			            goto screen_password_when_add_recovery
		            end_if
				else
					if cmp [counter_add_recovery_email] "60"
						delay_sec 1
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
                                    delay_sec 1
                                    ctrl_back
                                    delay_sec 2
                                    goto screen_password_when_add_recovery	
                                end_if
                                
                            else	
                                concat "Waiting load new screen recovery email:   " [counter_add_recovery_email] debug_counter_add_recovery_email
                                concat [debug_counter_add_recovery_email] "/100" debug_counter_add_recovery_email
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
while chk_limit 200
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
			delay_sec 1
			delay_sec 1
			touch_xy 439 1115
			delay_sec_rnd 1 2
			text_auto_typing 400 qwerty [password]
			delay_sec 1
			ctrl_back
			goto screen_result_add_password_recovery
		else
			delay_sec 1
			touch_xy 439 950
			ctrl_back
			goto screen_result_add_password_recovery
		end_if
	else
		if chk_text "You have security" 0
			delay_sec 1
			goto you_have_security_recommendations
		else			
			if chk_text "To review and adjust your security settings" 0
				if chk_text "Sign in" 0
					delay_sec 1
					touch_text "Sign in" 0
					delay_sec 2
					goto you_have_security_recommendations
				end_if
			else	
				if chk_text "Sign out and turn off sync" 0
					delay_sec 1
					goto fail
				else
					if chk_text "SELECT ALL" 0 
						delay_sec 1
						ctrl_back
					else					
						concat "Waiting load page email recovery:   " [counter_wait_load_page_add_recovery] debug_counter_wait_load_page_add_recovery
						concat [debug_counter_wait_load_page_add_recovery] "/200" debug_counter_wait_load_page_add_recovery
						toast   [debug_counter_wait_load_page_add_recovery]

                        if cmp [counter_wait_load_page_add_recovery] "15"
						    if chk_text "Search or type web address" 0
                                delay_sec_rnd 2 3
                                goto  add_recovery_email
                            end_if
						end_if

						if cmp [counter_wait_load_page_add_recovery] "20"
							delay_sec 1
							swipe_xy 1200 500 down 726 1693
							delay_sec 2
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "30"
							delay_sec 1
							swipe_xy 1200 500 down 726 1693
							delay_sec 2
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "40"
							delay_sec 1
							swipe_xy 1200 500 down 726 1693
							delay_sec 2
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "50"
							delay_sec 1
							swipe_xy 1200 500 down 726 1693
							delay_sec 2
						end_if

                        if cmp [counter_wait_load_page_add_recovery] "60"
							delay_sec 1
							swipe_xy 1200 500 down 726 1693
							delay_sec 2
						end_if

                          if cmp [counter_wait_load_page_add_recovery] "70"
                            delay_sec_rnd 2 3
                             touch_xyxy 444 152 972 209 
                             delay_sec_rnd 2 3
							 touch_xy 1341 2203
							 delay_sec 1
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
		delay_sec 1
		touch_text "Recovery email" 0
		goto screen_password_when_add_recovery		
	else
		if chk_text "Signed in to Google as" 0
			// toast "Signed in to Google as"
			// toast "back"
			// ctrl_back
			// delay_sec 3
			// toast "refresh page"
			// swipe_xy 1200 500 down 726 1693
			// delay_sec 2
			// toast "goto screen_password_when_add_recovery"
			// goto screen_password_when_add_recovery	
			goto fail
		else
			delay_sec 1
			swipe_xy 726 1693 up 1200 500
		end_if
	end_if		
end_while
goto reboot



tag screen_result_add_password_recovery
toast "screen_result_add_password_recovery"
set_num counter_Waiting_screen_result_add_password_recovery 0
while chk_limit 120
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
			delay_sec_rnd 2 3
		end_while
	else
	inc_num counter_Waiting_screen_result_add_password_recovery

	if chk_text "Search or type web address" 0
		delay_sec_rnd 2 3
		goto add_recovery_email
	end_if	

		concat "Waiting_screen_result_add_password_recovery:   " [counter_Waiting_screen_result_add_password_recovery] debug_counter_Waiting_screen_result_add_password_recovery
        concat [debug_counter_Waiting_screen_result_add_password_recovery] "/120" debug_counter_Waiting_screen_result_add_password_recovery
        toast  [debug_Waiting_screen_result_add_password_recovery]

		

	end_if
	delay_rnd 200 300
end_while
goto reboot


tag screen_type_email_recovery
toast "screen_type_email_recovery"
set_num counter_wait_load_page 0

while chk_limit 120
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
		delay_sec 1		
	//	swipe_xyxy 145 1260 145 1260 1000
		delay_sec 1	
		touch_xy 617 1555
	    delay_sec_rnd 4 5				
		// touch_xy 617 1555
		// delay_sec_rnd 3 4
		delay_sec 3
		touch_xy 118 2244
		delay_sec 2
		text_auto_typing 400 qwerty [email_recovery]
		delay_sec 1
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
					delay_sec 1
				end_if
			end_if
			delay_sec_rnd 1 2
		end_while
		goto reboot
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
			delay_sec 1
			goto reboot
		else
			if chk_text "You're not signed in" 0
				delay_sec 1
				goto reboot
			else
                
				if cmp [counter_wait_load_page] "20"
                    delay_sec_rnd 1 2
                     if chk_text "To continue," 0
			            goto screen_password_when_add_recovery
		            end_if
				else
					if cmp [counter_wait_load_page] "40"
						delay_sec 1
						swipe_xy 1200 500 down 726 1693
					else
                        if cmp [counter_wait_load_page] "60"
                            delay_sec 1
						    swipe_xy 1200 500 down 726 1693
                        else
                            if cmp [counter_wait_load_page] "80"
                                delay_sec 1
						         swipe_xy 1200 500 down 726 1693
                            else
                                if cmp [counter_wait_load_page] "100"
                                   delay_sec_rnd 2 3
									touch_xyxy 444 152 972 209 
									delay_sec_rnd 2 3
									touch_xy 1341 2203
									delay_sec 1
									goto add_recovery_email
                                else    
                                    if chk_text "Wrong password" 0 
                                        inc_num counter_wrong_password_login
                                        if cmp [counter_wrong_password_login] "2"
                                            goto reboot
                                        else
                                            delay_sec 1
                                            ctrl_back
                                            delay_sec 2
                                            goto screen_password_when_add_recovery	
                                        end_if
                                        
                                    else	
                                        concat "Waiting load new screen recovery email:   " [counter_wait_load_page] debug_counter_wait_load_page
                                        concat [debug_counter_wait_load_page] "/120" debug_counter_wait_load_page
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



tag screen_after_type_email_recovery
toast "screen_after_type_email_recovery"
set_num counter_wait_done_email_recovery 0
while chk_limit 120
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
				delay_sec 1
			end_if
		end_while
		goto reboot
	else
		if chk_text "To continue," 0
			goto screen_password_when_add_recovery
		else 
			if chk_text "complete this action" 0
				delay_sec 1
				swipe_xy 1200 500 down 726 1693
			else
				if gt_eq [counter_wait_done_email_recovery] 40 
					delay_sec 1
					swipe_xy 1200 500 down 726 1693
				    delay_sec 1
					delay_sec 5
					goto screen_type_email_recovery
				else
					concat "case After verify recovery email:   " [counter_wait_done_email_recovery] debug_counter_wait_done_email_recovery
					concat [debug_counter_wait_done_email_recovery] "/120" debug_counter_wait_done_email_recovery
					toast [debug_counter_wait_done_email_recovery]
					if cmp [counter_wait_done_email_recovery] "50"
						delay_sec 1
						swipe_xy 1200 500 down 726 1693
					end_if

				end_if
			end_if	
		end_if
	end_if
end_while
goto reboot


tag screen_review_account_info
set_num counter_wait_new_screen_review_info 0
while chk_limit 60
	delay_sec 1
	inc_num counter_wait_new_screen_review_info
	if chk_text "Next" 0
		touch_text "Next" 0
		while chk_limit 60
			if chk_text "Review your account info" 0				
				concat "Waiting load new screen:   " [counter_wait_new_screen_review_info] debug_counter_wait_new_screen_review_info
				concat [debug_counter_wait_new_screen_review_info] "/60" debug_counter_wait_new_screen_review_info
				delay_sec 1
			else
				goto check_current_screen
			end_if			
		end_while
		
	end_if
	delay_rnd 200 300
end_while
goto clear_app


tag screen_choose_personalization_setting
while chk_limit 60	
	delay_sec 1
	if chk_text "Express personalization" 0
		delay_sec 1
		touch_text "Express personalization" 0
		delay_sec 1
		delay_sec 3

		while chk_limit 60
			if chk_text "Next" 0
				toast "Touch Next"
				touch_text "Next" 0
				goto screen_confirm_personalization_setting
			end_if
			delay_rnd 200 300	
		end_while
	end_if
	
	delay_rnd 200 300
end_while
goto clear_app


tag screen_confirm_personalization_setting
while chk_limit 60
	if chk_text "Confirm personalization settings" 0
		delay_sec 1
		while chk_limit 60
			if chk_text "Back" 1
				delay_sec 1
				touch_text "Confirm" 1
				delay_sec 1
				goto screen_Privacy_and_Terms
			else
				delay_sec 1
				swipe_xy 726 1693 up 1200 500
			end_if
			delay_rnd 200 300
		end_while
		goto clear_app
	end_if
	delay_rnd 200 300
end_while
goto clear_app


tag screen_Privacy_and_Terms
while chk_limit 60
	if chk_text "Privacy and Terms" 0
		delay_sec 1
		while chk_limit 60
			if chk_text "I agree" 1
				delay_sec 1
				touch_text "I agree" 1
				delay_sec 1
				goto screen_result_of_create_email
			else
				if chk_text "Create Account" 0
					delay_sec 1
					delay_sec 1
					touch_text "I agree to the Google Terms" 0
					delay_sec 1
					if chk_text "I agree to the Location Terms" 0
						touch_text "I agree to the Location Terms" 0
						delay_sec 1
					end_if
					if chk_text "I agree to the processing" 0
						touch_text "I agree to the processing" 0
						delay_sec 1
					end_if
					
					touch_text "Create Account" 0
					delay_sec 1
					goto screen_result_of_create_email
				else
					delay_sec 1
					swipe_xy 726 1693 up 1200 500
				end_if
			end_if
			delay_rnd 200 300
		end_while

	end_if
	delay_rnd 200 300
end_while
goto fail



tag clear_app
inc_num counter_try_clear_app
concat "In tag clear_app:   " [counter_try_clear_app] debug_counter_try_clear_app
delay_sec 1
if gt_eq [counter_try_clear_app] 6
	delay_sec 1
	while chk_limit 20			
		if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2"
			toast "Save info error to server"
			goto mail_fail_getbk
		else
			delay_sec 1			
		end_if
	end_while
	goto mail_fail_getbk
end_if

ctrl_recents 
delay_sec 1
while chk_limit 60			
	if chk_text "Clear ALL" 0
		delay_sec 1
		touch_text "Clear ALL" 0		
		delay_sec 2		
		goto start_script
	else
		if chk_text "scriptctl" 0 
			goto start_script
		else
			if chk_text "No recent items" 0
				goto start_script
			else
				toast "swipe down"	
				swipe_xy 1200 500 down 726 1693
			end_if
		end_if
	end_if
	delay_rnd 200 300	
	goto start_script	
end_while
goto clear_app


tag fail
delay_sec 1
while chk_limit 20			
	if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=2"
		toast "Save infor error to server"
		goto mail_fail_getbk
	else
		delay_sec 1		
	end_if
end_while
goto mail_fail_getbk



tag could_not_sign_in
while chk_limit 60
	delay_sec 1
	goto clear_app
	delay_rnd 200 300
end_while


tag mail_fail_getbk
while chk_limit 30
	if
		delay_sec 1
		if server_data_get "http://127.0.0.1:9466/bkrsgmail?clear=1"
			delay 100
			toast "clear1|1"
		end_if    
		goto reboot
	end_if
end_while


tag reboot
while chk_limit 60
	delay_sec 1
	if server_data_get "http://127.0.0.1:9466/stop"
	
	end_if

	while chk_limit 20
		if server_data_get "http://127.0.0.1:9466/runscript?sf=script.txt"
			toast "runscript.txt ok"		
		else
			delay_sec 1
		end_if	
		delay_sec 15
	end_while
	delay_sec 1
end_while


tag start_download_app

//set_num_rnd choose_app_random 1 2

  if cmp [choose_app_random] "0"
	 toast "KuBet"
	 set_str app_name           			"pub:JOHNNIE JASON BEZZINA"
	 set_str key_search_app             "pub:JOHNNIE JASON BEZZINA"
	 set_str key_compare_chplay          "WINTBR | NỀN TẢNG UY TÍN"
	 set_str key_compare_chplay_2         "WINTBR | NỀN TẢNG UY TÍN"
  
 end_if
 
  if cmp [choose_app_random] "1"
	 toast "KuBet"
	 set_str app_name           			"pub:Don Aramyde"
	 set_str key_search_app             "pub:Don Aramyde"
	 set_str key_compare_chplay          "KUBET totemiacursed"
	 set_str key_compare_chplay_2         "KUBET totemiacursed"   
 end_if
   if cmp [choose_app_random] "2"
	 toast "KuBet"
	 set_str app_name           			"pub:JOHNNIE JASON BEZZINA"
	 set_str key_search_app             "pub:JOHNNIE JASON BEZZINA"
	 set_str key_compare_chplay          "WINTBR | NỀN TẢNG UY TÍN"
	 set_str key_compare_chplay_2         "WINTBR | NỀN TẢNG UY TÍN" 
 end_if

 

 
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
	if chk_text "Search" 0 
		toast "have search bar chplay"
		touch_text "Search" 0 
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
		
		if chk_text "Try again" 0
			toast "Try again"
			delay_sec_rnd 1 2
			touch_xy 700 1200
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
		if chk_text "Try again" 0
			toast "Try again"
			delay_sec_rnd 1 2
			touch_xy 700 1200
		end_if
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
		delay_sec_rnd 8 10		
		//goto screen_download_done
		//goto write_a_reviews
	else
		toast "Please waiting load screen install"
		if chk_text "Play" 0||chk_text "Open" 0
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
while chk_limit 10
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
		delay_sec_rnd 3 4
		touch_xy 1176 738
		delay_sec_rnd 3 4
		text_auto_typing 400 qwerty [info_name]
		//text_set "good"
		delay_sec_rnd 2 3
		if chk_text "POST" 0
			toast "POST"
			delay_sec_rnd 1 2
			touch_text "POST" 0
			delay_sec_rnd 5 7
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
		
		inc_num number_install
		inc_num choose_app_random
		
		toast "Swipe up"
		delay_sec_rnd 1 2
		swipe_xy 820 1479 down  820 407
		delay_sec_rnd 1 2
		toast "Swipe up"
		swipe_xy 820 1479 down  820 407
		delay_sec_rnd 1 2
		swipe_xy 820 1479 down  820 407
		delay_sec_rnd 1 2
		toast "Swipe up"
		swipe_xy 820 1479 down  820 407
		delay_sec_rnd 1 2
		
		if chk_text "Uninstall" 0
			toast "install done"
			delay_sec_rnd 2 3
			
			if gt_eq [choose_app_random] 1
				delay_sec 1			
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"	
				delay_sec_rnd 2 3			
				toast "Save install done to server"
				end_if					
				goto reboot
			else 
				goto start_download_app 
			end_if
		end_if
	else
		if chk_text "Try again" 0
			toast "Try again"
			delay_sec_rnd 1 2
			touch_xy 700 1200
		end_if
		
		if chk_text "No reviews yet" 0
			toast "No reviews yet"
			delay_sec_rnd 1 2			 
			goto start_download_app
		end_if
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
			if gt_eq [choose_app_random] 1
				delay_sec 1			
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"	
				delay_sec_rnd 2 3			
				toast "Save install done to server"
				end_if					
				goto reboot
			else 
				goto start_download_app 
			end_if
	else		
		if chk_text "Uninstall" 0
			toast "install done"
			delay_sec_rnd 2 3
			if gt_eq [choose_app_random] 1
				delay_sec 1			
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"	
				delay_sec_rnd 2 3			
				toast "Save install done to server"
				end_if					
				goto reboot
			else 
				goto start_download_app 
			end_if
			
			while chk_limit 10								
				if server_data_get "http://[sv_service_ip]:[sv_mail_port]/data-resource/update?data=[___device_id]&resource=manual,[type_source_email]&id=[___id]&job=[job_name]&key=(()Ap1@ut0mAtions!@@!!&status=999&&proxyname=install_done"				
					toast "Save install done to server"
					if server_data_get "http://127.0.0.1:9466/bkrsgmail?bk=[email]&password=[password]&rsmail=[email_recovery]&mid=[___id]&msource=[type_source_email]&clear=1"
		    	        delay 100
		             end_if
					delay_sec_rnd 2 3 
				else
					toast "Saving install done to server"		

				end_if
				delay_sec_rnd 1 2
					
			end_while
			
			
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
						toast "Swipe up"
						delay_sec_rnd 1 2
						swipe_xy 820 1479 down  820 407
						delay_sec_rnd 1 2
						toast "Swipe up"
						swipe_xy 820 1479 down  820 407
						delay_sec_rnd 1 2
						toast "Swipe up"
						swipe_xy 820 1479 down  820 407
						delay_sec_rnd 1 2
						toast "Swipe up"
						swipe_xy 820 1479 down  820 407						
						delay_sec_rnd 1 2
						touch_text "Play" 0
						if chk_text "Search" 0 
							toast "have search bar chplay"
							goto start_download_app
						else
						 	
						end_if
						if chk_text "Get Started" 1
							toast "start_download_app"
							delay_sec_rnd 1 2
							goto start_download_app
						 else
						 	
						end_if
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