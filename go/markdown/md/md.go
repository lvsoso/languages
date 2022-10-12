package md

import (
	"fmt"
	"path"
	"regexp"
	"strings"
)

var linkRe = regexp.MustCompile("\\[([^\\]]+)\\]\\(([^)]+)\\)")

func MdHandle(data string, virPath string) string {
	return linkRe.ReplaceAllStringFunc(data, func(m string) string {
		fmt.Println(m)
		l := strings.Index(m, "(")
		r := strings.Index(m, ")")
		if l < 0 || r < 0 || r-l <= 0 {
			return m
		}

		raw := strings.Trim(m[l+1:r], " ")
		if len(raw) == 0 {
			return m
		}
		fmt.Println(raw)

		newPath := path.Join(virPath, raw)
		fmt.Println(newPath)

		return m[:l+1] + newPath + m[r:]
	})
}
