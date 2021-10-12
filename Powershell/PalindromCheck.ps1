unction Test–IsPalindrome {
    [cmdletbinding()]
    Param(
    [Parameter(Position=0,Mandatory=$True,ValueFromPipeline=$True)]
    [ValidateNotNullorEmpty()]
    [string]$Text,
    [switch]$IgnoreSpace
    )
    Process {
        Write-Verbose "Testing $Text"
        if ($IgnoreSpace) {
            Write-Verbose "Removing spaces from text"
            $text = $text.Replace(" ","")
            Write-Verbose $text
        }
        $l = $text.length
        Write-Verbose "Length is $l"
        $mid = [math]::Truncate($l/2)
        Write-Verbose "Midpoint is $mid"

        #could also use Substring()
        $start = –join ($text[0..($mid–1)]) #$text.Substring(0,($mid)) 
        $end = –join ($text[–1..–($mid)]) 
        Write-Verbose "Start: $start"
        Write-Verbose "Pivot: $($Text[$mid])"
        Write-Verbose "End  : $end"
        if ($start -eq $end) {
         $True
        }
        else {
         $false
        }

    } 
    }  